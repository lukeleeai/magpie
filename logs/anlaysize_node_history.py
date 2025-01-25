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

def filter_children_by_fitness(file_path):
    with open(file_path, 'r') as file:
        data = json.load(file)

    for key, value in data.items():
        parent_fitnesses = value['parent_fitnesses']
        parent_codes = value['parent_codes']
        filtered_children = [
            child for child in value['children']
            if all(child['fitness'] < parent_fitness for parent_fitness in parent_fitnesses)
        ]
        value['children'] = filtered_children

    return data

# Usage
# walk through all the json files in "logs/train"

for file in os.listdir('logs/train'):
    if file.endswith('.json'):
        improved_operations = filter_children_by_fitness(f'logs/train/{file}')
        for branch in improved_operations.values():
            converted_data = convert_to_prompt_data(branch)
            print(converted_data)
            # print(branch["parent_fitnesses"])
            # print(branch['parent_codes'])
            break
        break