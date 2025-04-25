import os

from .known import algos as known_algos
from .known import edits as known_edits
from .known import models as known_models
from .known import protocols as known_protocols
from .known import software as known_software

from magpie.core.llm import LLMCrossover, LLMMutation
from magpie.utils.constants import (
    CROSSOVER,
    BASELINE_LLM,
    EOC_FINETUNED_LLM,
    PIE_FINETUNED_LLM,
    PIE_EOC_FINETUNED_LLM,
)


def llm_model_name_from_string(s):
    if s == BASELINE_LLM:
        return "gpt-4o-mini"
    elif s == EOC_FINETUNED_LLM:
        return "ft:gpt-4o-mini-2024-07-18:prompt-infection::AtfYDdzA"
    elif s == PIE_FINETUNED_LLM:
        raise NotImplementedError("PIE finetuned LLM not implemented")
    elif s == PIE_EOC_FINETUNED_LLM:
        raise NotImplementedError("PIE EOC finetuned LLM not implemented")
    else:
        raise ValueError(f"Unknown LLM model name: {s}")


def model_from_string(s):
    for klass in known_models:
        if klass.__name__ == s:
            return klass
    msg = f'Unknown model class "{s}"'
    raise RuntimeError(msg)


def edit_from_string(s):
    for klass in known_edits:
        if klass.__name__ == s:
            return klass
    msg = f'Unknown edit class "{s}"'
    raise RuntimeError(msg)


def protocol_from_string(s):
    for klass in known_protocols:
        if klass.__name__ == s:
            return klass
    msg = f'Unknown protocol class "{s}"'
    raise RuntimeError(msg)


def software_from_string(s):
    for klass in known_software:
        if klass.__name__ == s:
            return klass
    msg = f'Unknown software class "{s}"'
    raise RuntimeError(msg)


def algo_from_string(s):
    for klass in known_algos:
        # print("Klass: ", klass.__name__)
        if klass.__name__ == s:
            return klass
    msg = f'Unknown algorithm class "{s}"'
    raise RuntimeError(msg)

def convert_to_prompt_data(log):
    # Determine the operation type and select the appropriate prompt template
    is_crossover = log["operation_type"] == CROSSOVER
    num_offsprings = len(log["children"])

    # Select the appropriate prompt template and data
    prompt_template = (
        LLMCrossover.prompt if is_crossover else LLMMutation.prompt
    )

    if is_crossover:
        prompt_data = {
            "codes_and_fitnesses": format_crossover_parents(
                log["parent_codes"], log["parent_fitnesses"]
            ),
            "num_offsprings": num_offsprings,
        }
    else:
        prompt_data = {
            "code": log["parent_codes"][0],
            "fitness": log["parent_fitnesses"][0],
            "num_offsprings": num_offsprings,
            "reflections": "",
        }

    # Generate the initial prompt
    prompt = prompt_template.invoke(prompt_data).messages[0].content.strip()

    # Append child-specific information to the prompt
    for child in log["children"]:
        prompt += (
            f"\n```\n"
            f"Strategy: {child['strategy']}\n"
            f"{'Crossover' if is_crossover else 'Mutated'} code: {child['new_code']}\n"
            f"Fitness score: {child['fitness']}\n"
            f"```\n"
        )

    # print("PROMPT: ", prompt)
    return prompt


def get_log_dir(software_path, search_algorithm, reflection, pop_size=None):
    log_dir = os.path.join("logs", software_path.split("/")[-1]) + "/"
    if "LLM" in search_algorithm:
        if pop_size == 1:
            log_dir += "llm_baseline"
            return log_dir
        else:
            log_dir += "sbco_agent"

        if reflection == "SUCCESSFUL":
            log_dir += "_reflection_on_successful"
        elif reflection == "ALL":
            log_dir += "_reflection_on_all"
        else:
            log_dir += "_no_reflection"
    else:
        log_dir += "gp"
    return log_dir
