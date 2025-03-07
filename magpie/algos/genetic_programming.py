import copy
import math
import random
from collections import defaultdict
import json
import os
import re
import time

import magpie.core
import magpie.utils
from magpie.core.llm import LLMMutation, LLMCrossover, LLMReflection
from magpie.utils.constants import (
    LLM_MUTATION,
    LLM_CROSSOVER,
    MUTATION,
    CROSSOVER,
)

from magpie.utils.convert import (
    convert_to_prompt_data,
)
from magpie.utils.csv_manager import PromptsDataset


class GeneticProgramming(magpie.core.BasicAlgorithm):
    def __init__(self):
        super().__init__()
        self.name = "Genetic Programming"
        self.config["pop_size"] = 10
        self.config["delete_prob"] = 0.5
        self.config["offspring_elitism"] = 0.1
        self.config["offspring_crossover"] = 0.5
        self.config["offspring_mutation"] = 0.4
        self.config["batch_reset"] = True

        self.node_history = defaultdict(lambda: {"children": []})
        self.prompts_dataset = PromptsDataset()
        self.llm_reflection = LLMReflection()
        self.reflections = []

    def reset(self):
        super().reset()
        self.stats["gen"] = 0

    def setup(self, config):
        print("Config: ", config)
        super().setup(config)
        sec = config["search.gp"]
        self.config["pop_size"] = int(sec["pop_size"])
        self.config["delete_prob"] = float(sec["delete_prob"])
        self.config["offspring_elitism"] = float(sec["offspring_elitism"])
        self.config["offspring_crossover"] = float(sec["offspring_crossover"])
        self.config["offspring_mutation"] = float(sec["offspring_mutation"])
        self.config["uniform_rate"] = float(sec["uniform_rate"])
        self.dataset = config["software"]["path"].split("/")[-2]
        self.id = config["software"]["path"].split("/")[-1]
        # self.llm_type = sec["llm_type"]

        print("Dataset: ", self.dataset)
        print("ID: ", self.id)

        tmp = sec["batch_reset"].lower()
        if tmp in ["true", "t", "1"]:
            self.config["batch_reset"] = True
        elif tmp in ["false", "f", "0"]:
            self.config["batch_reset"] = False
        else:
            msg = "[search.gp] batch_reset should be Boolean"
            raise magpie.core.ScenarioError(msg)

    def aux_log_counter(self):
        gen = self.stats["gen"]
        step = self.stats["steps"] % self.config["pop_size"] + 1
        return f"{gen}-{step}"

    def add_node_history(self, child):
        print("\033[92mOperation type: ", child.operation_type, "\033[0m")
        parent_name = "(" + "x".join(child.parents_names) + ")"
        print(f"\033[92mAdding {child.name} to {parent_name}\033[0m")
        self.node_history[parent_name]["operation_type"] = child.operation_type
        self.node_history[parent_name]["parent_names"] = child.parents_names
        self.node_history[parent_name]["parent_codes"] = child.parents_codes
        self.node_history[parent_name][
            "parent_fitnesses"
        ] = child.parents_fitnesses

        new_code = child.get_patched_code()
        new_child = {
            "fitness": child.fitness,
            "new_code": new_code,
            "strategy": child.strategy,
        }
        # Skip if exists, otherwise append
        children = self.node_history[parent_name]["children"]
        for i, child in enumerate(children):
            if child["new_code"] == new_code:
                children[i] = new_child
                break
        else:
            children.append(new_child)

    def create_empty_variant(self):
        sol = magpie.core.Patch()
        source_code = magpie.core.Variant(self.software, sol)
        return source_code

    def mutate_original(self, num_mutations):
        source_code = self.create_empty_variant()
        mutations = self.mutate(source_code, num_mutations)
        return mutations

    def format_code(self, code):
        # Use regex to find all numbers in the string
        numbers = re.findall(r"\d+", code)
        # Join the numbers with a '+' sign
        return ("+".join(numbers)).replace("+x", "x")

    def save_node_history_to_file(self):
        """Save the node history to a local JSON file."""
        path = f"logs/{self.dataset}/{self.id}.json"
        print("Saving node history to: ", path)
        # Ensure the directory exists
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, "w") as file:
            json.dump(self.node_history, file, indent=4)

    def run(self):
        try:
            print("--------------------------------")
            print("Software: ", self.software)
            print("--------------------------------")

            # warmup
            self.hook_warmup()
            self.warmup()

            # early stop if something went wrong during warmup
            if self.report["stop"]:
                return

            # start!
            self.hook_start()

            # Unlike before, we now use variants instead of patches

            # initial pop
            pop = {}
            local_best_fitness = None
            mutations = self.mutate_original(self.config["pop_size"])

            for variant in mutations:
                # print("Variant name: ", variant.name)
                run = self.evaluate_variant(variant, force=True)
                accept = best = False
                if run.status == "SUCCESS":
                    variant.fitness = run.fitness
                    self.add_node_history(variant)
                    code = variant.get_patched_code()
                    name = variant.name
                    with open(f"/home/luke/magpie/logs/codes/with_crossover/{variant.fitness}_{name}.txt", "w") as f:
                        f.write(code)
                    if self.dominates(run.fitness, local_best_fitness):
                        local_best_fitness = run.fitness
                        accept = True
                        if self.dominates(
                            run.fitness, self.report["best_fitness"]
                        ):
                            self.report["best_fitness"] = run.fitness
                            self.report["best_patch"] = variant
                            self.report["best_patch_step"] = self.stats[
                                "steps"
                            ]
                            best = True
                else:
                    code = variant.get_patched_code()
                    name = variant.name
                    with open(f"/home/luke/magpie/logs/codes/with_crossover/failed_{name}.txt", "w") as f:
                        f.write(code)

                # reflection = self.llm_reflection.reflect(variant, run.status)
                # self.reflections.append(reflection)

                self.hook_evaluation(variant, run, accept, best)
                pop[variant] = run
                self.stats["steps"] += 1
                print("\033[94mInitial Step: ", self.stats["steps"], "\033[0m")

                time.sleep(1)

            print("Population keys:")
            for key in pop.keys():
                print(key)

            print("================================================")

            # main loop
            while not self.stopping_condition():
                time.sleep(1)
                self.stats["gen"] += 1
                print(">>>>>>>>Entering Main Loop: ", self.stats["gen"])
                self.hook_main_loop()
                offsprings = []
                parents = self.select(pop)

                # elitism
                copy_parents = copy.deepcopy(parents)
                k = int(
                    self.config["pop_size"] * self.config["offspring_elitism"]
                )
                for parent in copy_parents[:k]:
                    offsprings.append(parent)

                # crossover
                copy_parents = copy.deepcopy(parents)
                k = int(
                    self.config["pop_size"]
                    * self.config["offspring_crossover"]
                )
                if k > 0:
                    crossover_offsprings = self.crossover(copy_parents[:k], k)
                    offsprings.extend(crossover_offsprings)

                # mutation
                copy_parents = copy.deepcopy(parents)
                k = int(
                    self.config["pop_size"] * self.config["offspring_mutation"]
                )
                for parent in copy_parents[:k]:
                    # parents are already variants
                    # generate 3 mutations for each parent
                    mutations = self.mutate(parent, 1)
                    offsprings.extend(mutations)

                # regrow
                mutations = self.mutate_original(
                    self.config["pop_size"] - len(offsprings)
                )
                offsprings.extend(mutations)

                # replace
                pop.clear()
                local_best_fitness = None
                # print("Pop size: ", self.config["pop_size"])
                # print("Offsprings size: ", len(offsprings))
                # print the offsprings
                # for variant in offsprings:
                #     print("Offspring: ", variant.name)

                for variant in offsprings:
                    if self.stopping_condition():
                        break
                    if len(variant.patch.edits) > 2:
                        print(
                            "Patched Code: ", variant.get_patched_code()[-20:]
                        )

                    run = self.evaluate_variant(variant, force=True)
                    accept = best = False
                    if run.status == "SUCCESS":
                        variant.fitness = run.fitness
                        code = variant.get_patched_code()
                        name = variant.name
                        with open(f"/home/luke/magpie/logs/codes/with_crossover/{variant.fitness}_{name}.txt", "w") as f:
                            f.write(code)
                        self.add_node_history(variant)
                        if self.dominates(run.fitness, local_best_fitness):
                            local_best_fitness = run.fitness
                            accept = True
                            if self.dominates(
                                run.fitness, self.report["best_fitness"]
                            ):
                                self.report["best_fitness"] = run.fitness
                                self.report["best_patch"] = variant
                                self.report["best_patch_step"] = self.stats[
                                    "steps"
                                ]
                                best = True
                    else:
                        code = variant.get_patched_code()
                        name = variant.name
                        with open(f"/home/luke/magpie/logs/codes/with_crossover/failed_{name}.txt", "w") as f:
                            f.write(code)

                    # reflection = self.llm_reflection.reflect(
                    #     variant, run.status
                    # )
                    # self.reflections.append(reflection)

                    self.hook_evaluation(variant, run, accept, best)
                    pop[variant] = run
                    self.stats["steps"] += 1
                    print(
                        "\033[94mSecond Step: ", self.stats["steps"], "\033[0m"
                    )

            # print("--------------------------------")
            # for sol in pop.keys():
            #     print("Sol: ", len(sol.edits))
            # print("--------------------------------")

            print("=====================")
            print("Node history")

            self.node_history = {
                k: self.node_history[k] for k in sorted(self.node_history)
            }

            # for parent_name, log in self.node_history.items():
            #     prompt_data = convert_to_prompt_data(log)
            #     self.prompts_dataset.add_prompt(
            #         self.dataset + self.id, parent_name, prompt_data
            #     )
            print("=====================")

            # Save node history to a file
            self.save_node_history_to_file()

        except KeyboardInterrupt:
            self.report["stop"] = "keyboard interrupt"

        finally:
            # the end
            self.hook_end()

    def mutate(self, patch):
        if patch.edits and random.random() < self.config["delete_prob"]:
            del patch.edits[random.randrange(0, len(patch.edits))]
        else:
            patch.edits.append(self.create_edit(self.software.noop_variant))

    def crossover(self, sol1, sol2):
        c = copy.deepcopy(sol1)
        for edit in sol2.edits:
            c.edits.append(edit)
        return c

    def filter(self, pop):
        return {sol for sol in pop if pop[sol].status == "SUCCESS"}

    def select(self, pop):
        """returns possible parents ordered by fitness"""
        return sorted(self.filter(pop), key=lambda sol: pop[sol].fitness)

    def hook_main_loop(self):
        if self.config["batch_reset"]:
            for a in self.config["batch_bins"]:
                random.shuffle(a)
            self.hook_reset_batch()


class GeneticProgrammingLLM(GeneticProgramming):
    def __init__(self):
        super().__init__()
        self.name = "Genetic Programming (LLM)"
        self.llm_type = "baseline"
        self.llm_mutator = LLMMutation()
        self.llm_crossover = LLMCrossover()

    def mutate(self, variant, num_mutations):
        new_mutations = []
        parent_name = variant.name or "source"
        parent_code = variant.get_patched_code()
        parent_fitness = variant.fitness or self.report["reference_fitness"]

        strategies, code_changes = self.llm_mutator.mutate(
            source_code=parent_code,
            target_code=parent_code,
            target_fitness=parent_fitness,
            num_offsprings=num_mutations,
            reflections=self.reflections,
        )

        for strategy, mutation_code_changes in zip(strategies, code_changes):
            print("Mutating")
            # print("\n===Mutating variant: ", parent_name, "===")
            # print("Mutation: ", mutation)
            new_mutation = self.create_edit(
                self.software.noop_variant,
                operation_type=LLM_MUTATION,
                code_changes=mutation_code_changes,
            )
            new_variant = copy.deepcopy(variant)
            new_variant.strategy = strategy
            new_variant.apply_patch(new_mutation)
            new_variant.set_parents(
                MUTATION, [parent_name], [parent_code], [parent_fitness]
            )
            new_mutations.append(new_variant)

            print("New mutation: ", new_variant.name, "\n\n")

        print("Mutation done!")

        return new_mutations

    def crossover(self, parents, num_crossovers):
        new_crossovers = []
        parent_names = [parent.name for parent in parents]
        parent_codes = [parent.get_patched_code() for parent in parents]
        parent_fitnesses = [
            parent.fitness or self.report["reference_fitness"]
            for parent in parents
        ]
        # codes_and_fitnesses = format_crossover_parents(
        #     parent_codes, parent_fitnesses
        # )
        original_source_code = self.software.noop_variant.get_patched_code()
        
        strategies, code_changes = self.llm_crossover.crossover(
            parent_codes, parent_fitnesses, num_crossovers, original_source_code
        )

        for strategy, code_change in zip(strategies, code_changes):
            print("Crossovering")
            new_crossover = self.create_edit(
                self.software.noop_variant,
                operation_type=LLM_CROSSOVER,
                code_changes=code_change,
            )
            new_variant = self.create_empty_variant()
            new_variant.strategy = strategy
            new_variant.apply_patch(new_crossover)
            new_variant.set_parents(
                CROSSOVER,
                parent_names,
                parent_codes,
                parent_fitnesses,
            )
            new_crossovers.append(new_variant)

            print("New crossover: ", new_variant.name, "\n\n")

        print("Crossover done!")

        return new_crossovers


magpie.utils.known_algos.append(GeneticProgrammingLLM)


class GeneticProgrammingConcat(GeneticProgramming):
    def __init__(self):
        super().__init__()
        self.name = "Genetic Programming (Concat)"

    def crossover(self, sol1, sol2):
        c = copy.deepcopy(sol1)
        for edit in sol2.edits:
            c.edits.append(edit)
        return c


magpie.utils.known_algos.append(GeneticProgrammingConcat)


class GeneticProgramming1Point(GeneticProgramming):
    def __init__(self):
        super().__init__()
        self.name = "Genetic Programming (1-point)"

    def crossover(self, sol1, sol2):
        c = magpie.core.Patch()
        k1 = random.randint(0, len(sol1.edits))
        k2 = random.randint(0, len(sol2.edits))
        for edit in sol1.edits[:k1]:
            c.edits.append(edit)
        for edit in sol2.edits[k2:]:
            c.edits.append(edit)
        return c


magpie.utils.known_algos.append(GeneticProgramming1Point)


class GeneticProgramming2Point(GeneticProgramming):
    def __init__(self):
        super().__init__()
        self.name = "Genetic Programming (2-point)"

    def crossover(self, sol1, sol2):
        c = magpie.core.Patch()
        k1 = random.randint(0, len(sol1.edits))
        k2 = random.randint(0, len(sol1.edits))
        k3 = random.randint(0, len(sol2.edits))
        k4 = random.randint(0, len(sol2.edits))
        for edit in sol1.edits[: min(k1, k2)]:
            c.edits.append(edit)
        for edit in sol2.edits[min(k3, k4) : max(k3, k4)]:
            c.edits.append(edit)
        for edit in sol1.edits[max(k1, k2) :]:
            c.edits.append(edit)
        return c


magpie.utils.known_algos.append(GeneticProgramming2Point)


class GeneticProgrammingUniformConcat(GeneticProgramming):
    def __init__(self):
        super().__init__()
        self.name = "Genetic Programming (uniform+concatenation)"
        self.config["uniform_rate"] = 0.5

    def crossover(self, sol1, sol2):
        c = magpie.core.Patch()
        for edit in sol1.edits:
            if random.random() > self.config["uniform_rate"]:
                c.edits.append(edit)
        for edit in sol2.edits:
            if random.random() > self.config["uniform_rate"]:
                c.edits.append(edit)
        if len(c.edits) == 0:
            sol3, sol4 = (
                [sol1, sol2] if random.random() > 0.5 else [sol2, sol1]
            )
            if sol3.edits:
                c.edits.append(random.choice(sol3.edits))
            elif sol4.edits:
                c.edits.append(random.choice(sol4.edits))
        return c


magpie.utils.known_algos.append(GeneticProgrammingUniformConcat)


class GeneticProgrammingUniformInter(GeneticProgramming):
    def __init__(self):
        super().__init__()
        self.name = "Genetic Programming (uniform+interleaved)"
        self.config["uniform_rate"] = 0.5

    def crossover(self, sol1, sol2):
        c = magpie.core.Patch()
        l1 = [
            (i / len(sol1.edits), 0)
            for i in sorted(
                random.sample(
                    range(len(sol1.edits)),
                    math.ceil(len(sol1.edits) * self.config["uniform_rate"]),
                )
            )
        ]
        l2 = [
            (i / len(sol2.edits), 1)
            for i in sorted(
                random.sample(
                    range(len(sol2.edits)),
                    math.ceil(len(sol2.edits) * self.config["uniform_rate"]),
                )
            )
        ]
        for x, k in sorted(l1 + l2):
            sol = [sol1, sol2][k]
            edit = sol.edits[int(x * len(sol.edits))]
            c.edits.append(edit)
        if len(c.edits) == 0:
            sol3, sol4 = (
                [sol1, sol2] if random.random() > 0.5 else [sol2, sol1]
            )
            if sol3.edits:
                c.edits.append(random.choice(sol3.edits))
            elif sol4.edits:
                c.edits.append(random.choice(sol4.edits))
        return c


magpie.utils.known_algos.append(GeneticProgrammingUniformInter)
