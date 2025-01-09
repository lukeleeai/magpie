import abc
import random
import time

import magpie.settings


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
        self.report["stop"] = None

    @abc.abstractmethod
    def run(self):
        pass

    def get_edits(self, get_llm=False):
        # get edits for LineLLMMutation
        edits = self.config["possible_edits"]
        if get_llm:
            return [e for e in edits if e.__name__ == "LineLLMMutation"]
        else:
            return [e for e in edits if e.__name__ != "LineLLMMutation"]

    def create_edit(self, variant=None):
        """
        Create an edit for the given variant or the software's noop variant.

        This method randomly selects a class from the possible edits and attempts
        to create an edit using the selected class. If it fails to create an edit
        after a specified number of retries, it raises a RuntimeError.

        Args:
            variant: The variant to create an edit for. If None, the software's
                     noop variant is used.

        Returns:
            The created edit.
        """
        ref = variant or self.software.noop_variant
        llm_prob = self.config["llm_prob"]
        llm_edits = self.get_edits(get_llm=True)
        non_llm_edits = self.get_edits(get_llm=False)

        if len(llm_edits) > 0 and random.random() < llm_prob:
            # use LineLLMMutation
            klass = llm_edits[0]
        else:
            # use other edits
            klass = random.choice(non_llm_edits)

        tries = magpie.settings.edit_retries
        while (edit := klass.auto_create(ref)) is None:
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
        print(f"\033[91mStep: {self.stats['steps']}\033[0m")
        # prin the stop steps in red
        print(f"\033[91mStop Steps: {self.stop['steps']}\033[0m")

        if self.report["stop"] is not None:
            print(
                "(Abstract Algorithm) Stopping Condition: ",
                self.report["stop"],
            )
            return True
        if self.stop["budget"] is not None:
            if self.stats["budget"] >= self.stop["budget"]:
                print("(Abstract Algorithm) Stopping Condition: budget")
                self.report["stop"] = "budget"
                return True
        if self.stop["wall"] is not None:
            now = time.time()
            if now >= self.stats["wallclock_start"] + self.stop["wall"]:
                print("(Abstract Algorithm) Stopping Condition: time budget")
                self.report["stop"] = "time budget"
                return True
        if self.stop["steps"] is not None:
            if self.stats["steps"] >= self.stop["steps"]:
                print("(Abstract Algorithm) Stopping Condition: step budget")
                self.report["stop"] = "step budget"
                return True
        if self.stop["fitness"] is not None:  # todo: list
            if self.report["best_fitness"] is not None:
                if self.report["best_fitness"] <= self.stop["fitness"]:
                    print(
                        "(Abstract Algorithm) Stopping Condition: target fitness reached"
                    )
                    self.report["stop"] = "target fitness reached"
                    return True
        print("Not stopping")
        return False
