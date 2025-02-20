#!/usr/bin/env bash

mkdir -p perf
perf stat -e cycles,task-clock ./build/src_code < ~/eoc/magpie2/dataset/public_test_cases/p00041/input.0.txt 2>&1 | awk '/cycles/ {cycles=$1} /elapsed/ {time=$1} END {print cycles, time}'
perf stat -e cycles,task-clock ./build/src_code < ~/eoc/magpie2/dataset/public_test_cases/p00041/input.1.txt 2>&1 | awk '/cycles/ {cycles=$1} /elapsed/ {time=$1} END {print cycles, time}'
