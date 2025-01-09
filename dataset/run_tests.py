import argparse
import subprocess
import glob
import os


def run_test(executable_path, input_file, output_file):
    # Run the program with input file
    with open(input_file, "r") as f:
        process = subprocess.run(
            [executable_path], input=f.read(), capture_output=True, text=True
        )

    # Compare with expected output
    with open(output_file, "r") as f:
        expected_output = f.read().strip()
        actual_output = process.stdout.strip()
        return expected_output == actual_output


def main():
    # 1. Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("id", help="test id")
    parser.add_argument("problem_id", help="problem id")
    args = parser.parse_args()

    # 2. Get test files
    dataset_dir = os.path.dirname(
        os.path.abspath(__file__)
    )  # Gets the directory containing run_tests.py
    test_dir = os.path.join(dataset_dir, "public_test_cases", args.problem_id)
    input_files = sorted(glob.glob(f"{test_dir}/input.*.txt"))
    print("Input files:", input_files)

    # 3. Run tests and compare outputs
    executable = os.path.join(
        dataset_dir,
        "magpie_dataset",
        "test",
        args.id,
        "_magpie_work",
        "build",
        "src_code",
    )
    passed = 0
    total = len(input_files)

    for input_file in input_files:
        # Get corresponding output file
        output_file = input_file.replace("input", "output")

        if run_test(executable, input_file, output_file):
            passed += 1

    failed = total - passed

    # 4. Print results in the required format
    print(f"Tests run: {total}")
    print(f"Failures: {failed}")

    return failed > 0


if __name__ == "__main__":
    exit(main())
