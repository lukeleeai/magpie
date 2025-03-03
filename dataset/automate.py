import json
import os
import glob
import argparse
import subprocess
from magpie.core.llm import LLMTestAugmentation
import pandas as pd

visited_test_cases = set()


def load_jsonl_samples(num_data=3, dataset_name="test"):
    samples = []
    if dataset_name == "test":
        dataset_path = "dataset/test.jsonl"
    else:
        dataset_path = f"dataset/train_hq_only.jsonl"
    with open(dataset_path, "r") as file:
        for i, line in enumerate(file):
            if i >= num_data:
                break
            samples.append(json.loads(line))
    return samples


def make_cmake_file(data_dir, use_target_code=False):
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
        if use_target_code:
            print("Using target code")
            f.write("add_executable(src_code target.cpp)\n")
        else:
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


def to_tilde_path(path):
    home = os.path.expanduser("~")
    if path.startswith(home):
        return path.replace(home, "~", 1)
    return path


def create_run_file(
    data_dir, problem_id, max_runs=50, use_multipass=False, llm=None
):
    test_case_dir = os.path.abspath(f"dataset/public_test_cases/{problem_id}")
    visited_test_cases.add(test_case_dir)

    input_files = sorted(
        glob.glob(os.path.expanduser(f"{test_case_dir}/input.*.txt"))
    )
    num_runs = 0
    max_runs = 1

    current_dir = os.getcwd()

    # get source.cpp inside data_dir
    print(f"source code: {data_dir}/source.cpp")
    print("-----")
    with open(f"{data_dir}/source.cpp", "r") as f:
        source_code = f.read()

    with open(f"{data_dir}/run.sh", "w") as f:
        f.write("#!/usr/bin/env bash\n\n")
        f.write("mkdir -p perf\n")
        # print("Num runs: ", num_runs)
        # print("Max runs: ", max_runs)
        # print("Num input files: ", len(input_files))
        while num_runs < max_runs:
            for input_file in input_files:
                f.write(
                    f"perf stat -e cycles,task-clock,instructions ./build/src_code < {to_tilde_path(input_file)} 2>&1 | "
                    "awk '/cycles/ {cycles=$1} /elapsed/ {time=$1} /instructions/ {instructions=$1} END {print cycles, time, instructions}'\n"
                )
            num_runs += 1

    num_runs = 0

    return

    # if the augemented_run.sh exists, just return
    if os.path.exists(f"{data_dir}/augmented_run.sh"):
        return

    with open(f"{data_dir}/augmented_run.sh", "w") as f:
        f.write("#!/usr/bin/env bash\n\n")
        f.write("mkdir -p perf\n")
        # Use the local build directory instead of project root
        while num_runs < max_runs:
            for input_file in input_files:
                augmented_input_file = input_file.replace(
                    "input", "augmented_input"
                )
                # create augmented input file
                # first get the input file content
                with open(input_file, "r") as input_f:
                    input_content = input_f.read() 

                augmented_input_content = input_content

                if len(input_content.strip()) > 0:
                    print("Augmenting input file: ", input_file)
                    augmented_input_content = llm.augment_test(
                        source_code, input_content
                    )
                    print("Augmented input content: ", augmented_input_content)
                else:
                    augmented_input_content = input_content

                # print("augmented input content: \n", augmented_input_content)
                # then create the augmented input file
                with open(augmented_input_file, "w") as augmented_input_f:
                    augmented_input_f.write(augmented_input_content)

                # let's run the source code with the augmented input file right here to see if it's valid
                # and the time limit should be 1 minute
                # if it returns an error, feed it back to the LLM to fix the test inputs.
                # if it runs successfully, then we can use this augmented input file.
                # now write the fucking code!
                # time out = 60 seconds

                # first compile the source code using the compile.sh file
                # try:
                #     # temporarily CD into the data_dir
                #     os.chdir(data_dir)
                #     setup_result = subprocess.run(
                #         ["bash", "setup.sh"], check=True
                #     )
                #     compile_result = subprocess.run(
                #         ["bash", "compile.sh"], check=True
                #     )

                #     if compile_result.returncode != 0:
                #         print("Compilation failed")
                #         os.chdir(current_dir)
                #         return
                # except subprocess.CalledProcessError as e:
                #     print(f"Error during setup/compile: {e}")
                #     os.chdir(current_dir)
                #     return

                # command = [
                #     "./build/src_code",
                #     "<",
                #     to_tilde_path(augmented_input_file),
                # ]
                # try:
                #     # Using subprocess.run instead of Popen
                #     result = subprocess.run(
                #         command,
                #         stdout=subprocess.PIPE,
                #         stderr=subprocess.PIPE,
                #         text=True,
                #         timeout=30,  # timeout in seconds
                #     )
                #     # Handle the result
                #     stderr = result.stderr
                #     return_code = result.returncode

                #     if return_code != 0:
                #         print("Error: ", stderr)
                # except subprocess.TimeoutExpired:
                #     print("Program timed out after 30 seconds")
                #     return None
                # # feed it back to the LLM to fix the test inputs.
                # os.chdir(current_dir)

                f.write(
                    f"perf stat -e cycles,task-clock ./build/src_code < {to_tilde_path(augmented_input_file)} 2>&1 | "
                    "awk '/cycles/ {cycles=$1} /elapsed/ {time=$1} END {print cycles, time}'\n"
                )

                num_runs += 1
                if num_runs >= max_runs:
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




def create_cpp_file(data_dir, code, filename):
    # Replace the non-standard <bits/stdc++.h> with a custom "stdc++.h" header
    # because <bits/stdc++.h> is a GCC-specific header not available in Clang
    # or other compilers by default. The custom "stdc++.h" includes necessary
    # standard headers for cross-compiler compatibility.
    code = code.replace("<bits/stdc++.h>", '"stdc++.h"')
    with open(f"{data_dir}/{filename}", "w") as f:
        f.write(code)



# def create_source_cpp_file(data_dir, src_code):
#     # Replace the non-standard <bits/stdc++.h> with a custom "stdc++.h" header
#     # because <bits/stdc++.h> is a GCC-specific header not available in Clang
#     # or other compilers by default. The custom "stdc++.h" includes necessary
#     # standard headers for cross-compiler compatibility.
#     src_code = src_code.replace("<bits/stdc++.h>", '"stdc++.h"')
#     with open(f"{data_dir}/source.cpp", "w") as f:
#         f.write(src_code)


# def create_target_cpp_file(data_dir, tgt_code):
#     tgt_code = tgt_code.replace("<bits/stdc++.h>", '"stdc++.h"')
#     with open(f"{data_dir}/target.cpp", "w") as f:
#         f.write(tgt_code)


def copy_stdc_file(data_dir):
    with open("dataset/stdc++.h", "r") as f:
        stdc_content = f.read()
    with open(f"{data_dir}/stdc++.h", "w") as f:
        f.write(stdc_content)


def generate_data(
    data,
    index,
    one_shot=False,
    use_target_code=False,
    data_dir=None,
    dataset_name="test",
    max_runs=20,
    llm=None,
):
    # Create directory with padded number (e.g., 0000, 0001, etc.)
    id = f"{index:04d}"
    if data_dir == None:
        if use_target_code:
            data_dir = f"dataset/magpie_dataset/target_code/{id}"
        else:
            data_dir = f"dataset/magpie_dataset/{dataset_name}/{id}"
    print("Generating data for", data_dir)
    os.makedirs(data_dir, exist_ok=True)


    # Create all necessary files
    # check if data is a pd series
    # if it is, then we need to get the code from the series
    if isinstance(data, pd.Series):
        create_cpp_file(data_dir, data["code"], "source.cpp")
    else:
        if use_target_code:
            create_cpp_file(data_dir, data["tgt_code"], "target.cpp")
        else:
            create_cpp_file(data_dir, data["src_code"], "source.cpp")
            
    copy_stdc_file(data_dir)
    make_cmake_file(data_dir)
    make_setup_file(data_dir)
    create_compile_file(data_dir)
    create_run_file(data_dir, data["problem_id"], max_runs=max_runs, llm=llm)
    create_test_file(data_dir, data["problem_id"])
    create_scenario_file(data_dir, one_shot)


def generate_dataset(
    num_data=10,
    dataset_name="test",
    one_shot=False,
    use_target_code=False,
    max_runs=20,
):
    samples = load_jsonl_samples(num_data, dataset_name)
    llm = LLMTestAugmentation()
    for i, data in enumerate(samples):
        generate_data(
            data,
            i,
            one_shot,
            use_target_code,
            dataset_name=dataset_name,
            max_runs=max_runs,
            llm=llm,
        )


# Example usage
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--is_one_shot", action="store_true", help="Enable one shot mode"
    )
    parser.add_argument(
        "--dataset_name",
        type=str,
        help="Name of the dataset to generate",
        default="train",
    )
    parser.add_argument(
        "--num_data",
        type=int,
        default=30,
        help="Number of datasets to generate",
    )
    parser.add_argument(
        "--max_runs",
        type=int,
        default=1,
        help="Number of runs to repeat the code execution",
    )
    parser.add_argument(
        "--use_target_code",
        action="store_true",
        default=False,
        help="Use target code",
    )

    args = parser.parse_args()

    generate_dataset(
        args.num_data,
        args.dataset_name,
        args.is_one_shot,
        args.use_target_code,
        args.max_runs,
    )
