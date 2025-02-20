#!/bin/bash
do_llm_eoc=true
do_llm_one_shot=false
num_exp=1
num_data=100

# Run train dataset
dataset_name="train"
python dataset/automate.py --dataset_name $dataset_name --num_data $num_data

if $do_llm_eoc; then
    # LLM Evolution-of-Code
    echo "Running LLM Evolution-of-Code experiment $exp_id..."
    for problem_id in $(seq 40 $num_data); do  # problem_id
        formatted_problem_id=$(printf "%04d" $problem_id)  # Format the number with leading zeros
        echo "Running scenario $formatted_problem_id..."
        python magpie genetic_programming --scenario "dataset/magpie_dataset/$dataset_name/$formatted_problem_id/scenario.txt"
    done
fi

# if $do_llm_one_shot; then
#     # LLM One-Shot
#     for exp_id in {0..$num_exp}; do
#         echo "Running LLM One-Shot experiment $exp_id..."
#         for problem_id in {0..$num_data}; do
#             formatted_problem_id=$(printf "%04d" $problem_id)  # Format the number with leading zeros
#             echo "Running scenario $formatted_problem_id..."
#             python magpie genetic_programming --scenario "dataset/magpie_dataset/$dataset_name/$formatted_problem_id/scenario_one_shot.txt"
#         done
#     done
# fi


