import io
import os
import pathlib
import re
import shutil
import subprocess

import magpie.settings
import magpie.utils.known
from magpie.utils.csv_manager import ResultsManager


def apply_diff(source_code_path, diff_file):
    # 1. create a temporary file to copy the source code call it a "copy.cpp"
    temp_file = "copy.cpp"
    shutil.copy(source_code_path, temp_file)

    # 2. apply the diff to the "copy.cpp" file by running "patch copy.cpp diff_file"
    subprocess.run(["patch", temp_file, diff_file], check=True)

    # 3. read the "copy.cpp" file and return the content
    with open(temp_file, "r") as f:
        content = f.read()

    # 4. delete the "copy.cpp" file
    os.remove(temp_file)

    return content


class BasicProtocol:
    def __init__(self):
        self.search = None
        self.software = None
        self.results_manager = None

    def set_results_manager(self, config):
        if self.results_manager is not None:
            return

        is_one_shot = (
            int(config["search"]["max_steps"]) == 1
            and int(config["search.gp"]["pop_size"]) == 1
        )

        self.results_manager = ResultsManager()

    def run(self, config):
        self.set_results_manager(config)

        if self.software is None:
            msg = "Software not specified"
            raise AssertionError(msg)
        if self.search is None:
            msg = "Search not specified"
            raise AssertionError(msg)

        # setup search
        self.search.setup(config)

        # log config just in case
        with io.StringIO() as ss:
            config.write(ss)
            ss.seek(0)
            msg = "==== CONFIG ====\n%s"
            if magpie.settings.color_output:
                msg = f"\033[1m{msg}\033[0m"
            self.software.logger.debug(msg, ss.read())

        # init final result dict
        result = {"stop": None, "best_patch": None}

        # setup software
        self.search.software = self.software

        logger = self.software.logger

        # run the algorithm a single time
        logger.debug("")  # because CONFIG above is also debug
        msg = "==== SEARCH: %s ===="
        if magpie.settings.color_output:
            msg = f"\033[1m{msg}\033[0m"
        logger.info(msg, self.search.__class__.__name__)
        self.search.run()
        result.update(self.search.report)

        # print the report
        logger.info("")
        msg = "==== REPORT ===="
        if magpie.settings.color_output:
            msg = f"\033[1m{msg}\033[0m"
        logger.info(msg)
        logger.info("Termination: %s", result["stop"])
        for handler in logger.handlers:
            if handler.__class__.__name__ == "FileHandler":
                logger.info("Log file: %s", handler.baseFilename)
        if result["best_patch"] and result["best_patch"].patch.edits:
            base_path = (
                pathlib.Path(magpie.settings.log_dir) / self.software.run_label
            )
            patch_file = f"{base_path}.patch"
            diff_file = f"{base_path}.diff"
            logger.info("Patch file: %s", patch_file)
            logger.info("Diff file: %s", diff_file)

            tmp = result["reference_fitness"]
            if not isinstance(tmp, list):
                tmp = [tmp]
            logger.info(
                "Reference fitness: %s",
                " ".join(
                    [magpie.settings.log_format_fitness.format(x) for x in tmp]
                ),
            )
            tmp = result["best_fitness"]
            if not isinstance(tmp, list):
                tmp = [tmp]
            logger.info(
                "Best fitness: %s",
                " ".join(
                    [magpie.settings.log_format_fitness.format(x) for x in tmp]
                ),
            )

            logger.info("")
            msg = "==== BEST PATCH ====\n%s"
            diff = result["diff"]
            if magpie.settings.color_output:
                msg = "\033[1m==== BEST PATCH ====\033[0m\n%s"
                diff = self.color_diff(diff)
            logger.info(msg, result["best_patch"])

            logger.info("")
            msg = "==== DIFF ====\n%s"
            diff = result["diff"]
            if magpie.settings.color_output:
                msg = "\033[1m==== DIFF ====\033[0m\n%s"
                diff = self.color_diff(diff)
            logger.info(msg, diff)

            # for convenience, save best patch and diff to separate files
            with pathlib.Path(patch_file).open("w") as f:
                f.write(str(result["best_patch"]) + "\n")
            with pathlib.Path(diff_file).open("w") as f:
                f.write(result["diff"])

            # Here, let's get the actual code from the diff file
            # @LUKE TODO: Later make the path dynamic
            # source_code_path = f"dataset/magpie_dataset/test/{self.software.base_name}/{self.software.target_files[0]}"
            source_code_path = os.path.join(
                self.software.config["software"]["path"],
                self.software.target_files[0],
            )
            # apply diff to source code (without changing the source code file) and print the new code

            print(f"\033[95msource_code_path: {source_code_path}\033[0m")
            print(f"\033[95mdiff_file: {diff_file}\033[0m")

            model_code = apply_diff(source_code_path, diff_file).replace(
                "\n", "\\n"
            )
            print(f"\033[95mmodel_code: \n{model_code}\033[0m")

            # Save to results manager
            id = self.software.run_label.split("_")[0]
            self.results_manager.add_result(
                id=id,
                new_code=model_code,
                new_code_time=(
                    result["best_fitness"]
                    if isinstance(result["best_fitness"], (int, float))
                    else 0.0
                ),
                reference_time=(
                    result["reference_fitness"]
                    if isinstance(result["reference_fitness"], (int, float))
                    else 0.0
                ),
                llm_prob=config["search"]["llm_prob"],
            )

        # cleanup temporary software copies
        self.software.clean_work_dir()  # @luke : put back

    @staticmethod
    def color_diff(diff):
        out = diff[:]
        for patt, repl in [
            (r"^(\*\*\*\*.*)$", r"\033[36m\1\033[0m"),
            (r"^(--- .* ----)$", r"\033[36m\1\033[0m"),
            (r"^(\*\*\* .* \*\*\*\*)$", r"\033[36m\1\033[0m"),
            (r"^((?:---|\+\+\+|\*\*\*) .*)$", r"\033[1m\1\033[0m"),
            (r"^(-.*)$", r"\033[31m\1\033[0m"),
            (r"^(\+.*)$", r"\033[32m\1\033[0m"),
            (r"^(!.*)$", r"\033[33m\1\033[0m"),
            (r"^(@@ .* @@)", r"\033[36m\1\033[0m"),
        ]:
            out = re.sub(patt, repl, out, flags=re.MULTILINE)
        return out


magpie.utils.known_protocols.append(BasicProtocol)
