import abc
import random
import time

import magpie.settings

from magpie.utils.constants import LLM_MUTATION, LLM_CROSSOVER


class AbstractAlgorithm(abc.ABC):
    def __init__(self):
        self.software = None
        self.config = {}
        self.config["possible_edits"] = []
        self.stop = {}
        self.stop["wall"] = None  # seconds
        self.stop["steps"] = None
        self.stop["budget"] = None
        self.stop["fitness"] = None
        self.reset()

    def reset(self):
        self.stats = {}
        self.stats["budget"] = 0
        self.stats["steps"] = 0
        self.stats["wallclock_start"] = time.time()  # dummy
        self.report = {}
        self.report["initial_patch"] = None
        self.report["reference_patch"] = None
        self.report["reference_fitness"] = None
        self.report["best_fitness"] = None
        self.report["best_patch"] = None
        self.report["best_patch_step"] = None
        self.report["stop"] = None

    @abc.abstractmethod
    def run(self):
        pass

    def get_edit_class(self, operation_type=None):
        edits = self.config["possible_edits"]
        if operation_type == LLM_MUTATION:
            edit_name = "LineLLMMutation"
            return next(e for e in edits if e.__name__ == edit_name)
        elif operation_type == LLM_CROSSOVER:
            edit_name = "LineLLMCrossover"
            return next(e for e in edits if e.__name__ == edit_name)
        else:
            return random.choice([e for e in edits if "LLM" not in e.__name__])

    def create_edit(
        self,
        variant=None,
        operation_type=None,
        new_code=None,  # only for llm-based edits
        line_numbers=None,
    ):
        """
        Create an edit for the given variant or the software's noop variant.

        This method randomly selects a class from the possible edits and attempts
        to create an edit using the selected class. If it fails to create an edit
        after a specified number of retries, it raises a RuntimeError.

        Args:
            variant: The variant to create an edit for. If None, the software's
                     noop variant is used.
            operation_type: The type of operation to create an edit for.
            new_code: The new code created by the llm. Only for llm-based edits.
                      LLM generates multiple codes at once.
            line_numbers: The line numbers of the new code. Only for llm-based edits.
                          LLM generates multiple codes at once.

        Returns:
            The created edit.
        """
        ref = variant or self.software.noop_variant
        # llm_prob = self.config["llm_prob"]
        use_llm = (
            operation_type == LLM_MUTATION or operation_type == LLM_CROSSOVER
        )
        klass = self.get_edit_class(operation_type)

        tries = magpie.settings.edit_retries
        while (
            edit := (
                klass.auto_create(ref, new_code, line_numbers)
                if use_llm
                else klass.auto_create(ref)
            )
        ) is None:
            tries -= 1
            if tries == 0:
                msg = f"Unable to create an edit of class {klass.__name__}"
                raise RuntimeError(msg)
        return edit

    def dominates(self, fit1, fit2):
        if fit1 is None:
            return False
        if fit2 is None:
            return True
        if isinstance(fit1, list):
            for x, y in zip(fit1, fit2):
                if x < y:
                    return True
                if x > y:
                    return False
            return False
        return fit1 < fit2

    def stopping_condition(self):
        # print the stats step in red
        # log
        self.software.logger.info(f"Step: {self.stats['steps']}")
        # prin the stop steps in red
        self.software.logger.info(f"Stop Steps: {self.stop['steps']}")

        if self.report["stop"] is not None:
            self.software.logger.info(
                "(Abstract Algorithm) Stopping Condition: ",
                self.report["stop"],
            )
            return True
        if self.stop["budget"] is not None:
            if self.stats["budget"] >= self.stop["budget"]:
                self.software.logger.info("(Abstract Algorithm) Stopping Condition: budget")
                self.report["stop"] = "budget"
                return True
        if self.stop["wall"] is not None:
            now = time.time()
            if now >= self.stats["wallclock_start"] + self.stop["wall"]:
                self.software.logger.info("(Abstract Algorithm) Stopping Condition: time budget")
                self.report["stop"] = "time budget"
                return True
        if self.stop["steps"] is not None:
            if self.stats["steps"] >= self.stop["steps"]:
                self.software.logger.info("(Abstract Algorithm) Stopping Condition: step budget")
                self.report["stop"] = "step budget"
                return True
        if self.stop["fitness"] is not None:  # todo: list
            if self.report["best_fitness"] is not None:
                if self.report["best_fitness"] <= self.stop["fitness"]:
                    self.software.logger.info("(Abstract Algorithm) Stopping Condition: target fitness reached")
                    self.report["stop"] = "target fitness reached"
                    return True
        print("Not stopping")
        return False
