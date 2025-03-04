import pathlib
import subprocess
import re
import magpie.utils
from .abstract_model import AbstractLineModel
from magpie.core.llm import LLMMutation, LLMCrossover


class LineModel(AbstractLineModel):
    # Class-level cache for storing mutations
    mutation_cache = {}

    def __init__(self, filename):
        super().__init__(filename)

    def init_model(self, lines=None):
        self.init_contents(lines)
        self.init_cached_dump()

    def init_cached_dump(self):
        self.cached_dump = self.dump()

    def init_contents(self, lines=None):
        if lines is None:
            with pathlib.Path(self.filename).open("r") as target_file:
                lines = list(map(str.rstrip, target_file.readlines()))
        else:
            lines = lines.split("\n")

        n = len(lines)
        self.contents = lines
        self.locations = {
            "line": list(range(n)),
            "_inter_line": list(range(n + 1)),
        }
        self.locations_names = self.locations

    def dump(self):
        return "".join(s + "\n" for s in self.contents if s is not None)

    def show_location(self, target_type, target_loc):
        tag_start = ""
        tag_end = ""
        if magpie.settings.color_output:
            tag_start = f"\033[36m{tag_start}"
            tag_end = f"{tag_end}\033[0m"
        if target_type == "line":
            return f"{tag_start}{target_loc}:{tag_end}{self.contents[self.locations[target_type][target_loc]]}"
        if target_type == "_inter_line":
            if target_loc == 0:
                return f"{tag_start}0=before initial line{tag_end}"
            return f"{tag_start}{target_loc}=after:{tag_end}{self.contents[self.locations[target_type][target_loc-1]]}"
        raise ValueError

    def do_llm_mutation(self, llm_id, new_code, line_numbers):
        print("\033[35mApplying LLM Mutation to ", llm_id, "\033[0m")
        print("line_numbers: ", line_numbers)

        # extract the start and end number where there can be any string between them
        pattern = r'^(\d+).*?(\d+)$'
        match = re.match(pattern, line_numbers)
        start_line = int(match.group(1))
        end_line = int(match.group(2))
        print("\033[32mstart_line: ", start_line, "\033[0m")
        print("\033[32mend_line: ", end_line, "\033[0m")

        original_code = self.dump()
        original_code_lines = original_code.split("\n")
        new_code_lines = new_code.split("\n")
        patched_code_lines = original_code_lines[:start_line]
        patched_code_lines.extend(new_code_lines)
        patched_code_lines.extend(original_code_lines[end_line+1:])
        new_code = "\n".join(patched_code_lines)

        print("\033[33m" + "\n".join(original_code_lines[start_line-5:start_line]) + "\033[0m")
        print("\033[32m--------------------------------\033[0m")
        print("\033[32m" + "\n".join(new_code_lines) + "\033[0m") 
        print("\033[32m--------------------------------\033[0m")
        print("\033[33m" + "\n".join(original_code_lines[end_line+1:end_line+5]) + "\033[0m")

        print("\033[31m" + new_code + "\033[0m")
        
        self.init_contents(new_code)
        return True

    def do_llm_crossover(self, llm_id, new_code):
        print("\033[35mApplying LLM Crossover to ", llm_id, "\033[0m")
        self.init_contents(new_code)
        return True

    def do_replace(self, ref_model, target_dest, target_orig):
        d_f, d_t, d_i = target_dest  # file name, "line", line index
        o_f, o_t, o_i = target_orig  # file name, "line", line index
        if (
            d_f != self.filename
            or o_f != ref_model.filename
            or d_t != "line"
            or o_t != "line"
        ):
            raise ValueError
        old_line = self.contents[self.locations[d_t][d_i]]
        new_line = ref_model.contents[ref_model.locations[o_t][o_i]]
        if new_line is None or new_line == old_line:
            return False
        self.contents[self.locations[d_t][d_i]] = new_line
        return True

    def do_insert(self, ref_model, target_dest, target_orig):
        d_f, d_t, d_i = (
            target_dest  # file name, "_inter_line", interline index
        )
        o_f, o_t, o_i = target_orig  # file name, "line", line index
        if (
            d_f != self.filename
            or o_f != ref_model.filename
            or d_t != "_inter_line"
            or o_t != "line"
        ):
            raise ValueError
        new_line = ref_model.contents[ref_model.locations[o_t][o_i]]
        self.contents.insert(self.locations[d_t][d_i], new_line)
        # fix locations
        for i in range(d_i, len(self.locations["line"])):
            self.locations["line"][i] += 1
        for i in range(d_i, len(self.locations["_inter_line"])):
            self.locations["_inter_line"][i] += 1
        return True

    def do_delete(self, target):
        d_f, d_t, d_i = target  # file name, "line", interline index
        if d_f != self.filename or d_t != "line":
            raise ValueError
        old_line = self.contents[self.locations[d_t][d_i]]
        if old_line is None:
            return False
        self.contents[self.locations[d_t][d_i]] = None
        return True


magpie.utils.known_models.append(LineModel)
