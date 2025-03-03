#!/usr/bin/env bash

TEST_CASE_DIR="/home/luke/magpie/dataset/public_test_cases/p02314"

# Create directory for test outputs
mkdir -p test_outputs

# Run tests and capture outputs
for input in "$TEST_CASE_DIR"/input.*.txt; do
    base=$(basename "$input" | sed "s/input/output/")
    "$PWD/build/src_code" < "$input" > "test_outputs/$base"
done

total_tests=$(ls -1 "$TEST_CASE_DIR"/output.*.txt | wc -l)
echo "Tests run: $total_tests"

failures=0
for expected in "$TEST_CASE_DIR"/output.*.txt; do
    base=$(basename "$expected")
    if ! diff -b "$expected" "test_outputs/$base" > /dev/null; then
        ((failures++))
    fi
done

echo "Failures: $failures"
exit $((failures > 0))
