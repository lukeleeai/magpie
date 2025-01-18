#!/bin/bash
do_llm_eoc=true
do_llm_one_shot=true
num_exp=3

if $do_llm_one_shot; then
    # LLM One-Shot
    for exp_id in {2..$num_exp}; do
        echo "Running LLM One-Shot experiment $exp_id..."
        for problem_id in {0..15}; do
            formatted_problem_id=$(printf "%04d" $problem_id)  # Format the number with leading zeros
            echo "Running scenario $formatted_problem_id..."
            python magpie genetic_programming --scenario "dataset/magpie_dataset/test/$formatted_problem_id/scenario_one_shot.txt"
        done
    done
fi

if $do_llm_eoc; then
    # LLM Evolution-of-Code
    for exp_id in {2..$num_exp}; do
        echo "Running LLM Evolution-of-Code experiment $exp_id..."
        for problem_id in {0..15}; do  # problem_id
            formatted_problem_id=$(printf "%04d" $problem_id)  # Format the number with leading zeros
            echo "Running scenario $formatted_problem_id..."
            python magpie genetic_programming --scenario "dataset/magpie_dataset/test/$formatted_problem_id/scenario.txt"
        done
    done
fi


