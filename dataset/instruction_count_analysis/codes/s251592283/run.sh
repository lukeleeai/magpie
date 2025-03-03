#!/usr/bin/env bash

mkdir -p perf
perf stat -e cycles,task-clock,instructions ./build/src_code < ~/magpie/dataset/public_test_cases/p01368/input.0.txt 2>&1 | awk '/cycles/ {cycles=$1} /elapsed/ {time=$1} /instructions/ {instructions=$1} END {print cycles, time, instructions}'
perf stat -e cycles,task-clock,instructions ./build/src_code < ~/magpie/dataset/public_test_cases/p01368/input.1.txt 2>&1 | awk '/cycles/ {cycles=$1} /elapsed/ {time=$1} /instructions/ {instructions=$1} END {print cycles, time, instructions}'
