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

    def do_llm_operation(self, llm_id, code_changes, operation_type):
        print("\033[35mApplying LLM ", operation_type, " to ", llm_id, "\033[0m")

        original_code = self.dump()
        original_code_lines = original_code.split("\n")
        
        # Parse the target code into lines
        target_lines = original_code.strip().split('\n')

        # Group changes
        changes = []
        current_removals = []
        current_additions = []

        # Process each line in the code_change
        for line in code_changes.strip().split('\n'):
            if not line:
                continue
                
            # Use simple startswith for detecting markers
            if line.startswith('-'):
                # If we have collected removals and additions, and now see a new removal,
                # store the previous change group and start a new one
                if current_removals and current_additions:
                    changes.append((current_removals.copy(), current_additions.copy()))
                    current_additions = []
                    current_removals = []
                
                # Extract the content after the '-' but strip it for comparison
                content = line[1:].strip()
                current_removals.append(content)
            
            elif line.startswith('+'):
                # Extract the content after the '+' but preserve the whitespace
                content = line[1:]  # Keep the original spacing
                current_additions.append(content)

        # Add the last change group if it exists
        if current_removals or current_additions:
            changes.append((current_removals.copy(), current_additions.copy()))

        # Apply the changes to the target code
        result_lines = []
        i = 0

        while i < len(target_lines):
            matched = False
            
            for removals, additions in changes:
                # Check if we have enough lines left to match
                if i + len(removals) <= len(target_lines):
                    # Use regex to match each line, ignoring whitespace differences
                    match = True
                    for j, removal in enumerate(removals):
                        # Create a pattern that matches the line content, ignoring whitespace
                        pattern = r'^\s*' + re.escape(removal) + r'\s*$'
                        if not re.match(pattern, target_lines[i + j]):
                            match = False
                            break
                    
                    if match:
                        # Add the replacement lines with their original spacing
                        result_lines.extend(additions)
                        # Skip the removed lines
                        i += len(removals)
                        matched = True
                        break
            
            if not matched:
                result_lines.append(target_lines[i])
                i += 1

        patched_code = '\n'.join(result_lines)
        print("Patched code length: ", len(patched_code))

        self.init_contents(patched_code)
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
