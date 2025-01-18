import json
import os
import glob
import argparse


def load_jsonl_samples(count=3):
    samples = []
    with open("dataset/test.jsonl", "r") as file:
        for i, line in enumerate(file):
            if i >= count:
                break
            samples.append(json.loads(line))
    return samples


def make_cmake_file(data_dir):
    with open(f"{data_dir}/CMakeLists.txt", "w") as f:
        f.write("cmake_minimum_required(VERSION 3.0)\n")
        f.write("project(src_code)\n\n")
        # Use Clang (default on macOS)
        # Remove or comment out the GCC line
        # f.write('set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-14")\n')
        # Add C++17 support
        f.write("set(CMAKE_CXX_STANDARD 17)\n")
        f.write("set(CMAKE_CXX_STANDARD_REQUIRED ON)\n\n")
        # Add -O3 optimization
        f.write('set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")\n')
        # Specify the build type (e.g., Release, Debug)
        f.write("set(CMAKE_BUILD_TYPE Release)\n\n")
        # Add executable
        f.write("add_executable(src_code source.cpp)\n")


def make_setup_file(data_dir):
    with open(f"{data_dir}/setup.sh", "w") as f:
        f.write("#!/usr/bin/env bash\n\n")
        f.write("rm -rf build\n")
        f.write("mkdir build\n")
        f.write("cd build\n")
        f.write("cmake ..\n")
        # f.write("make\n")


def create_compile_file(data_dir):
    with open(f"{data_dir}/compile.sh", "w") as f:
        f.write("#!/usr/bin/env bash\n\n")
        f.write("cd build\n")
        f.write("cmake ..\n")
        f.write("make\n")


def create_run_file(data_dir, problem_id, max_runs=50, use_multipass=False):
    def to_tilde_path(path):
        home = os.path.expanduser("~")
        if path.startswith(home):
            return path.replace(home, "~", 1)
        return path

    test_case_dir = os.path.abspath(f"dataset/public_test_cases/{problem_id}")

    input_files = sorted(
        glob.glob(os.path.expanduser(f"{test_case_dir}/input.*.txt"))
    )
    total_runs = 0

    with open(f"{data_dir}/run.sh", "w") as f:
        f.write("#!/usr/bin/env bash\n\n")
        # Use the local build directory instead of project root
        while total_runs < max_runs:
            for input_file in input_files:
                # Use build/src_code from the current directory
                # f.write(f"./build/src_code < {to_tilde_path(input_file)}\n")
                f.write(f"./build/src_code < {input_file}\n")
                total_runs += 1
                if total_runs >= max_runs:
                    return


def create_test_file(data_dir, problem_id):
    test_case_dir = os.path.abspath(f"dataset/public_test_cases/{problem_id}")

    with open(f"{data_dir}/test.sh", "w") as f:
        f.write("#!/usr/bin/env bash\n\n")

        # Define test case directory in the shell script
        f.write(f'TEST_CASE_DIR="{test_case_dir}"\n\n')

        f.write("# Create directory for test outputs\n")
        f.write("mkdir -p test_outputs\n\n")

        # Run program for each input and save outputs
        f.write("# Run tests and capture outputs\n")
        f.write('for input in "$TEST_CASE_DIR"/input.*.txt; do\n')
        f.write('    base=$(basename "$input" | sed "s/input/output/")\n')
        f.write(
            '    "$PWD/build/src_code" < "$input" > "test_outputs/$base"\n'
        )
        f.write("done\n\n")

        # Count total tests using the defined variable
        f.write('total_tests=$(ls -1 "$TEST_CASE_DIR"/output.*.txt | wc -l)\n')
        f.write('echo "Tests run: $total_tests"\n\n')

        # Compare outputs and count differences
        f.write("failures=0\n")
        f.write('for expected in "$TEST_CASE_DIR"/output.*.txt; do\n')
        f.write('    base=$(basename "$expected")\n')
        f.write(
            '    if ! diff -b "$expected" "test_outputs/$base" > /dev/null; then\n'
        )
        f.write("        ((failures++))\n")
        f.write("    fi\n")
        f.write("done\n\n")

        f.write('echo "Failures: $failures"\n')
        f.write("exit $((failures > 0))\n")


def create_scenario_file(data_dir, one_shot=False):
    scenario_filename = "scenario"
    if one_shot:
        scenario_filename += "_one_shot"

    with open(f"dataset/{scenario_filename}.txt", "r") as template:
        scenario_content = template.read()

    scenario_content = scenario_content.replace(
        "path = ", f"path = {data_dir}"
    )
    # # Use absolute path for run_tests.py
    # abs_path = os.path.abspath("dataset/run_tests.py")
    # # scenario_content = scenario_content.replace(
    # #     "test_cmd = ", f"test_cmd = python {abs_path} {id} {problem_id}"
    # # )
    # # scenario_content = scenario_content.replace(
    # #     "work_dir = ", f"work_dir = {data_dir}/_magpie_work"
    # # )

    with open(f"{data_dir}/{scenario_filename}.txt", "w") as f:
        f.write(scenario_content)


def create_cpp_file(data_dir, src_code):
    # Replace the non-standard <bits/stdc++.h> with a custom "stdc++.h" header
    # because <bits/stdc++.h> is a GCC-specific header not available in Clang
    # or other compilers by default. The custom "stdc++.h" includes necessary
    # standard headers for cross-compiler compatibility.
    src_code = src_code.replace("<bits/stdc++.h>", '"stdc++.h"')
    with open(f"{data_dir}/source.cpp", "w") as f:
        f.write(src_code)


def copy_stdc_file(data_dir):
    with open("dataset/stdc++.h", "r") as f:
        stdc_content = f.read()
    with open(f"{data_dir}/stdc++.h", "w") as f:
        f.write(stdc_content)


def generate_data(data, index, one_shot=False, use_multipass=False):
    # Create directory with padded number (e.g., 0000, 0001, etc.)
    id = f"{index:04d}"
    data_dir = f"dataset/magpie_dataset/test/{id}"
    print("Generating data for", data_dir)
    os.makedirs(data_dir, exist_ok=True)

    # Create all necessary files
    create_cpp_file(data_dir, data["src_code"])
    copy_stdc_file(data_dir)
    make_cmake_file(data_dir)
    make_setup_file(data_dir)
    create_compile_file(data_dir)
    create_run_file(data_dir, data["problem_id"], 1, use_multipass)
    create_test_file(data_dir, data["problem_id"])
    create_scenario_file(data_dir, one_shot)


def generate_dataset(count=10, one_shot=False, use_multipass=False):
    samples = load_jsonl_samples(count)
    for i, data in enumerate(samples):
        generate_data(data, i, one_shot, use_multipass)


# Example usage
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--is_one_shot", action="store_true", help="Enable one shot mode"
    )
    parser.add_argument(
        "--num_data",
        type=int,
        default=15,
        help="Number of datasets to generate",
    )
    parser.add_argument(
        "--use_multipass",
        action="store_true",
        help="Use multipass mode",
    )

    args = parser.parse_args()

    generate_dataset(
        args.num_data,
        one_shot=args.is_one_shot,
        use_multipass=args.use_multipass,
    )
