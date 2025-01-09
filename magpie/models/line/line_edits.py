import magpie.utils
from magpie.core import Edit

from .abstract_model import AbstractLineModel


# LLM Mutation
class LineLLMMutation(Edit):
    llm_id = 0

    @classmethod
    def auto_create(cls, ref):
        target = ref.random_model(AbstractLineModel).llm_target(
            LineLLMMutation.llm_id
        )
        LineLLMMutation.llm_id += 1
        # print("\033[93mtarget: ", target, "\033[0m")
        if not target:
            return None
        return cls(target)

    def apply(self, ref, variant):
        model = variant.models[self.target[0]]
        llm_id = self.target[1]
        return model.do_llm_mutation(llm_id)


magpie.utils.known_edits.append(LineLLMMutation)


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
