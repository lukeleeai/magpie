#!/bin/bash
num_exp=15

for i in $(seq 1 $num_exp); do
    echo "Running Experiment $i"

    echo "Running WEKA"
    echo "Setting: GP"
    python magpie genetic_programming --scenario "dataset/weka/_magpie/scenario_gp.txt"
    echo "Setting: SBCO (ALL)"
    python magpie genetic_programming --scenario "dataset/weka/_magpie/scenario_sbco.txt" --reflection "ALL"
    echo "Setting: SBCO (SUCCESSFUL)"
    python magpie genetic_programming --scenario "dataset/weka/_magpie/scenario_sbco.txt" --reflection "SUCCESSFUL"
    echo "Setting: SBCO (NONE)"
    python magpie genetic_programming --scenario "dataset/weka/_magpie/scenario_sbco.txt" --reflection "NONE"

    # echo "Running SAT4J"
    # echo "Setting: GP"
    # python magpie genetic_programming --scenario "dataset/sat4j/_magpie/scenario_gp.txt"
    # echo "Setting: SBCO (ALL)"
    # python magpie genetic_programming --scenario "dataset/sat4j/_magpie/scenario_sbco.txt" --reflection "ALL"
    # echo "Setting: SBCO (SUCCESSFUL)"
    # python magpie genetic_programming --scenario "dataset/sat4j/_magpie/scenario_sbco.txt" --reflection "SUCCESSFUL"
    # echo "Setting: SBCO (NONE)"
    # python magpie genetic_programming --scenario "dataset/sat4j/_magpie/scenario_sbco.txt" --reflection "NONE"

    # echo "Running MINISAT"
    # echo "Setting: GP"
    # python magpie genetic_programming --scenario "dataset/minisat/_magpie/scenario_gp.txt"  # Baseline GP
    # echo "Setting: SBCO (ALL)"
    # python magpie genetic_programming --scenario "dataset/minisat/_magpie/scenario_sbco.txt" --reflection "ALL"
    # echo "Setting: SBCO (SUCCESSFUL)"
    # python magpie genetic_programming --scenario "dataset/minisat/_magpie/scenario_sbco.txt" --reflection "SUCCESSFUL"
    # echo "Setting: SBCO (NONE)"
    # python magpie genetic_programming --scenario "dataset/minisat/_magpie/scenario_sbco.txt" --reflection "NONE"

    echo "Experiment $i completed"
done
