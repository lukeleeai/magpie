import contextlib
import copy
import difflib
import random

import magpie.settings
import magpie.utils


class Variant:
    def __init__(self, software, patch=None):
        self.models = {}
        # If a noop_variant exists, copy its models
        self.software = software
        if software.noop_variant:
            self.models = copy.deepcopy(software.noop_variant.models)
        else:
            # If no patch is provided, raise an error
            if patch is not None:
                raise AssertionError
            # Initialize models for each target file
            with contextlib.chdir(software.path):
                for filename in software.target_files:
                    self.models[filename] = self._init_model(
                        software, filename
                    )

        self.patch = patch
        # Apply edits from the patch if it exists
        if patch:
            for edit in patch.edits:
                edit.apply(software.noop_variant, self)
        # Generate the diff for the variant
        self.diff = self._diff(
            software.noop_variant or self, magpie.settings.diff_method
        )

        self.name = None
        self.fitness = None

    def set_parents(self, operation_type, names, codes, fitnesses):
        """Set the parents for the variant

        :param operation_type: The type of operation that created the variant (mutate or crossover)
        :param names: The names of the parents
        :param codes: The codes of the parents
        :param fitnesses: The fitnesses of the parents
        """
        self.operation_type = operation_type
        self.parents_names = names
        self.parents_codes = codes
        self.parents_fitnesses = fitnesses

    def apply_patch(self, new_edit=None):
        # the previous patches were already applied
        # so we need to apply only the new patch
        self.patch.edits.append(new_edit)
        new_edit.apply(self.software.noop_variant, self)

        self.name = (
            "_".join([str(edit.target[1]) for edit in self.patch.edits])
            if self.patch
            else "source"
        )

    def __str__(self):
        # return the edits of a patch in a string
        return " + ".join([str(edit) for edit in self.patch.edits])

    def random_model(self, klass):
        # Select a random model of the specified class
        print("Random model of class: ", klass.__name__)
        print("Models: ", self.models)
        tmp = [
            model for model in self.models.values() if isinstance(model, klass)
        ]
        if tmp:
            return random.choice(tmp)
        msg = f'No compatible target file for model "{klass.__name__}"'
        raise RuntimeError(msg)

    def random_targets(self, klass, *args):
        # Get random targets for the specified class and tags
        klass = self.random_model(klass).__class__
        return [self.random_model(klass).random_target(tag) for tag in args]

    def _init_model(self, software, target_file):
        # Initialize the model based on the software's model rules
        for pattern, klass in software.model_rules:
            if any(
                [
                    target_file == pattern,
                    pattern == "*",
                    pattern.startswith("*")
                    and target_file.endswith(pattern[1:]),
                ]
            ):
                model = magpie.utils.model_from_string(klass)(target_file)
                break
        else:
            msg = f'Unknown model for target file "{target_file}"'
            raise RuntimeError(msg)
        # Setup the model using the software's model config
        for pattern, section_name in software.model_config:
            if any(
                [
                    target_file == pattern,
                    pattern == "*",
                    pattern.startswith("*")
                    and target_file.endswith(pattern[1:]),
                ]
            ):
                model.setup(software.config, section_name)
                break
        model.init_model()
        # # Initialize location names based on whether indirect locations exist
        # if model.indirect_locations:
        #     model.locations_names = {
        #         key: list(range(len(value)))
        #         for key, value in model.locations.items()
        #     }
        # else:
        #     model.locations_names = model.locations
        # model.cached_dump = model.dump()
        return model

    def _diff(self, other, method="unified"):
        # Determine the diff method to use
        if method == "unified":
            diff_method = difflib.unified_diff
        elif method == "context":
            diff_method = difflib.context_diff
        else:
            msg = f'Unknown diff method: "{method}"'
            raise ValueError(msg)
        diffs = []
        # Generate diffs for each model
        for filename in self.models:
            renamed = other.models[filename].renamed_filename
            fromfile = f"before: {renamed}"
            tofile = f"after: {renamed}"
            s1 = other.models[filename].dump().splitlines(keepends=True)
            s2 = self.models[filename].dump().splitlines(keepends=True)
            diffs += diff_method(s1, s2, fromfile=fromfile, tofile=tofile)
        return "".join(diffs)

    def get_patched_code(self):
        """Returns a dictionary of filename -> code after patch application"""
        # print("Fetching the code for variant: ", self.name)
        for filename in self.models:
            return self.models[filename].dump()

    def print_patch_and_code(self):
        """Prints both the patch diff and the resulting code for each modified file"""
        print("=== Patch Diff ===")
        print(self.diff)

        print("\n=== Resulting Code ===")
        for filename, code in self.get_patched_code().items():
            print(f"\n--- {filename} ---")
            print(code)
