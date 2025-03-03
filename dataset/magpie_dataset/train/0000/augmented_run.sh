#!/usr/bin/env bash

mkdir -p perf
perf stat -e cycles,task-clock ./build/src_code < ~/magpie/dataset/public_test_cases/p00000/augmented_input.1.txt 2>&1 | awk '/cycles/ {cycles=$1} /elapsed/ {time=$1} END {print cycles, time}'
