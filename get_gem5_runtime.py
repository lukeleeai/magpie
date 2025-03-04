from gem5 import simulator
import time
import argparse
import os
import base64


def get_gem5_runtime(code, problem_id):
    start_time = time.time()
    env = simulator.make(arch="X86-skylake", optimization_flag="-O3")
    print(
        f"[[[[Time taken to create environment: {time.time() - start_time} seconds]]]]]"
    )

    start_time = time.time()
    results = env.submit_single_submission(
        code, [0], problem_id, timing_env="gem5"
    )
    return results["agg_runtime"]


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Get gem5 runtime for a given code and problem ID"
    )
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument("--code", type=str, help="The code to run")
    group.add_argument(
        "--code-b64",
        type=str,
        help="Base64 encoded source code",
    )
    parser.add_argument(
        "--problem-id", type=str, required=True, help="The problem ID"
    )

    args = parser.parse_args()

    if args.code_b64:
        try:
            code = base64.b64decode(args.code_b64).decode()
        except Exception as e:
            print(f"Error decoding base64 source code: {e}")
            exit(1)
    else:
        code = args.code

    runtime = get_gem5_runtime(code, args.problem_id)
    print(f"Runtime: {runtime}")
