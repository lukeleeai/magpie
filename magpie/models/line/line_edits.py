import magpie.utils
from magpie.core import Edit

from .abstract_model import AbstractLineModel


# LLM Operations


class LineLLMMutation(Edit):
    llm_id = 0

    @classmethod
    def auto_create(cls, ref, new_code, line_numbers):
        target = ref.random_model(AbstractLineModel).llm_target(
            LineLLMMutation.llm_id
        )
        LineLLMMutation.llm_id += 1
        if not target:
            return None
        return cls(target, new_code, line_numbers)

    def apply(self, ref, variant):
        model = variant.models[self.target[0]]
        llm_id = self.target[1]
        new_code = self.data[0]
        line_numbers = self.data[1]
        return model.do_llm_mutation(llm_id, new_code, line_numbers)


magpie.utils.known_edits.append(LineLLMMutation)


class LineLLMCrossover(Edit):
    llm_id = 0

    @classmethod
    def auto_create(cls, ref, new_code):
        target = ref.random_model(AbstractLineModel).llm_target(
            LineLLMCrossover.llm_id
        )
        LineLLMCrossover.llm_id += 1
        if not target:
            return None
        return cls(target, new_code)

    def apply(self, ref, variant):
        model = variant.models[self.target[0]]
        llm_id = self.target[1]
        new_code = self.data[0]
        return model.do_llm_crossover(llm_id, new_code)


magpie.utils.known_edits.append(LineLLMCrossover)


class LineDeletion(Edit):
    @classmethod
    def auto_create(cls, ref):
        target = ref.random_model(AbstractLineModel).random_target("line")
        if not target:
            return None
        return cls(target)

    def apply(self, ref, variant):
        model = variant.models[self.target[0]]
        return model.do_delete(self.target)


magpie.utils.known_edits.append(LineDeletion)


class LineReplacement(Edit):
    @classmethod
    def auto_create(cls, ref):
        target, ingredient = ref.random_targets(
            AbstractLineModel, "line", "line"
        )
        if not (target and ingredient):
            return None
        return cls(target, ingredient)

    def apply(self, ref, variant):
        ingredient = self.data[0]
        ref_model = ref.models[ingredient[0]]
        model = variant.models[self.target[0]]
        return model.do_replace(ref_model, self.target, ingredient)


magpie.utils.known_edits.append(LineReplacement)


class LineInsertion(Edit):
    @classmethod
    def auto_create(cls, ref):
        target, ingredient = ref.random_targets(
            AbstractLineModel, "_inter_line", "line"
        )
        if not (target and ingredient):
            return None
        return cls(target, ingredient)

    def apply(self, ref, variant):
        ingredient = self.data[0]
        ref_model = ref.models[ingredient[0]]
        model = variant.models[self.target[0]]
        return model.do_insert(ref_model, self.target, ingredient)


magpie.utils.known_edits.append(LineInsertion)
