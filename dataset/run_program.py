import argparse
import subprocess
import glob


# Later change it to a bash script to minimize the python overhead


def run_program(executable_path, input_file):
    # Run the program with input file
    with open(input_file, "r") as f:
        subprocess.run(
            [executable_path], input=f.read(), capture_output=True, text=True
        )


def main():
    # 1. Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("id", help="test id")
    parser.add_argument("problem_id", help="problem id")
    args = parser.parse_args()

    # 2. Get test files
    test_dir = f"public_test_cases/{args.problem_id}"
    input_files = sorted(glob.glob(f"{test_dir}/input.*.txt"))

    # 3. Run program multiple times
    for i in range(10):
        executable = f"magpie_dataset/test/{args.id}/build/src_code"

        for input_file in input_files:
            run_program(executable, input_file)

    return 0


if __name__ == "__main__":
    exit(main())
