import json
import os

from magpie.core.llm import LLMMutation, LLMCrossover
from magpie.utils.constants import MUTATION, CROSSOVER
from magpie.utils.convert import convert_to_prompt_data


def get_prompt(operation_type):
    if operation_type == MUTATION:
        return LLMMutation.prompt
    elif operation_type == CROSSOVER:
        return LLMCrossover.prompt


def get_stats_per_file(file_path):
    stats = {
        "total_mutations": 0,
        "successful_mutations": 0,
        "total_crossovers": 0,
        "successful_crossovers": 0,
    }

    with open(file_path, "r") as file:
        branches = json.load(file)

    for key, value in branches.items():
        parent_fitnesses = value["parent_fitnesses"]
        min_parent_fitness = min(parent_fitnesses)

        if value["operation_type"] == MUTATION:
            for child in value["children"]:
                if child["fitness"] <= min_parent_fitness:
                    stats[
                        "successful_mutations"
                    ] += 1  # Increment successful mutations
                    break
            stats["total_mutations"] += 1  # Increment total mutations

        else:
            stats["total_crossovers"] += 1  # Increment total crossovers
            for child in value["children"]:
                if child["fitness"] <= min_parent_fitness:
                    stats[
                        "successful_crossovers"
                    ] += 1  # Increment successful crossovers
                    break

    return stats


def extract_prompts(branch):
    min_parent_fitness = min(branch["parent_fitnesses"])
    improved_children = [
        child
        for child in branch["children"]
        if child["fitness"] <= min_parent_fitness - 50000
    ]
    # print(str(len(branch["children"])) + " -> " + str(len(improved_children)))
    branch["children"] = improved_children

    if len(branch["children"]) == 0:
        return None

    prompt_data = convert_to_prompt_data(branch).replace("            ", " ")
    light_prompt_data = clean_prompt_data(prompt_data)
    user_prompt_end = (
        "Strictly follow the output format (e.g. strategy: ..., code: ...):"
    )

    user_prompt = light_prompt_data.split(user_prompt_end)[0] + user_prompt_end

    # print(f"\033[92mUSER PROMPT: {user_prompt}\033[0m")
    answer_prompt = light_prompt_data.split(user_prompt_end)[1]

    # print("ANSWER PROMPT: ", answer_prompt)

    return {
        "messages": [
            {
                "role": "system",
                "content": "You are a master of code optimization that can help perform genetic operations on code.",
            },
            {"role": "user", "content": user_prompt},
            {"role": "assistant", "content": answer_prompt},
        ]
    }


def clean_prompt_data(prompt_data):
    prefix_to_remove = "Here are some examples"
    suffix_to_remove = "The above are only examples."
    remove_start_idx = prompt_data.find(prefix_to_remove)
    remove_end_idx = prompt_data.find(suffix_to_remove) + len(suffix_to_remove)

    prompt_data = prompt_data[:remove_start_idx] + prompt_data[remove_end_idx:]
    prompt_data = prompt_data.replace("            ", " ")

    prefix_to_remove = "Here's an example an an output format."
    suffix_to_remove = "Now,"
    remove_start_idx = prompt_data.find(prefix_to_remove)
    remove_end_idx = prompt_data.find(suffix_to_remove)

    prompt_data = prompt_data[:remove_start_idx] + prompt_data[remove_end_idx:]
    prompt_data = prompt_data.replace("            ", " ")

    return prompt_data


# Usage
# walk through all the json files in "logs/train"


def analyze_node_history():
    total_mutations = 0
    total_successful_mutations = 0
    total_crossovers = 0
    total_successful_crossovers = 0
    for file in os.listdir("logs/train"):
        if file.endswith(".json"):
            stats = get_stats_per_file(f"logs/train/{file}")
            total_mutations += stats["total_mutations"]
            total_successful_mutations += stats["successful_mutations"]
            total_crossovers += stats["total_crossovers"]
            total_successful_crossovers += stats["successful_crossovers"]

    print(
        f"Total Mutations: {total_mutations}, Successful Mutations: {total_successful_mutations}"
    )
    print(
        f"Total Crossovers: {total_crossovers}, Successful Crossovers: {total_successful_crossovers}"
    )


def construct_dataset(dataset_type="train"):
    dataset_path = f"logs/{dataset_type}.jsonl"

    # remove the dataset file if it exists
    if os.path.exists(dataset_path):
        os.remove(dataset_path)

    # Iterate through all JSON files in the training logs directory
    for program in os.listdir("logs/train"):
        if program.endswith(".json"):
            # Open the JSON file and load branches
            with open(f"logs/train/{program}", "r") as file:
                branches = json.load(file)

                # Process each branch to extract prompts
                for branch in branches.values():
                    prompt_data = extract_prompts(branch)

                    # Only write to the dataset if the answer prompt is valid
                    if prompt_data is not None:
                        with open(dataset_path, "a") as dataset_file:
                            dataset_file.write(json.dumps(prompt_data))
                            dataset_file.write("\n")

    print("Num lines: ", sum(1 for _ in open(dataset_path)))


if __name__ == "__main__":
    construct_dataset()
