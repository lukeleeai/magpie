import os
import subprocess
from pathlib import Path
import numpy as np
import matplotlib.pyplot as plt
from tabulate import tabulate
import logging

# Set up logging configuration
logging.basicConfig(
    filename="fitness_variation.log",  # Log file name
    level=logging.INFO,  # Log level
    format="%(asctime)s - %(levelname)s - %(message)s",  # Log format
)


def run_script(script_path):
    try:
        result = subprocess.run(
            ["/bin/bash", script_path],
            check=True,
            capture_output=True,
            text=True,
        )
        return result.stdout
    except subprocess.CalledProcessError as e:
        print(f"Error running {script_path}: {e}")
        return None
    except Exception as e:
        print(f"Unexpected error with {script_path}: {e}")
        return None


def process_directories():
    # Get the train directory
    train_dir = Path("train").resolve()
    print("train_dir", train_dir)

    # Check if train directory exists
    if not train_dir.is_dir():
        print("Train directory not found!")
        return

    # Number of repeats to test
    num_repeats_list = [10, 20, 40, 60, 100, 500, 1000]
    mean_cv_cpu_cycles = []
    mean_cv_wall_clock = []

    for num_repeats in num_repeats_list:
        cv_cpu_cycles_list = []  # List to store CVs for each directory
        cv_wall_clock_time_list = []  # List to store CVs for each directory

        # Loop through all numbered directories from 0001 to 0020
        dir_patterns = [f"{i:04d}" for i in range(1, 10)]
        for dir_path in sorted(train_dir.glob(dir_patterns[0])) + sum([sorted(train_dir.glob(pattern)) for pattern in dir_patterns[1:]], []):
            if dir_path.is_dir():
                print(
                    f"\nProcessing directory: {dir_path} with {num_repeats} repeats"
                )
                logging.info(
                    f"\nProcessing directory: {dir_path} with {num_repeats} repeats"
                )

                # Change to the directory
                os.chdir(dir_path)

                # Clean existing build
                build_dir = Path("build")
                if build_dir.exists():
                    print("Removing existing build directory...")
                    subprocess.run(["rm", "-rf", "build"], capture_output=True)

                # Run scripts in sequence
                scripts = ["setup.sh", "compile.sh"]

                # Run setup.sh and compile.sh once
                for script in scripts:
                    script_path = Path(script)
                    if script_path.exists():
                        run_script(script_path)

                # Run run.sh num_repeats times and collect all fitness values
                all_cpu_cycles = []
                all_wall_clock_time = []
                for i in range(num_repeats):
                    run_script_path = Path("run.sh")
                    if run_script_path.exists():
                        output = run_script(run_script_path)
                        if output:
                            stats = output.strip().split("\n")
                            print("stats: ", stats)
                            cpu_cycles = [
                                int(x.split()[0].replace(",", ""))
                                for x in stats
                            ]
                            wall_clock_time = [
                                float(x.split()[1]) for x in stats
                            ]
                            all_cpu_cycles.extend(cpu_cycles)
                            all_wall_clock_time.extend(wall_clock_time)

                # Analyze combined results
                if all_cpu_cycles:
                    cpu_cycles_array = np.array(all_cpu_cycles)
                    mean = cpu_cycles_array.mean()
                    std_dev = cpu_cycles_array.std()
                    cv = (std_dev / mean) * 100 if mean != 0 else 0
                    cv_cpu_cycles_list.append(cv)

                if all_wall_clock_time:
                    wall_clock_time_array = np.array(all_wall_clock_time)
                    mean = wall_clock_time_array.mean()
                    std_dev = wall_clock_time_array.std()
                    cv = (std_dev / mean) * 100 if mean != 0 else 0
                    cv_wall_clock_time_list.append(cv)

                # Cleanup
                if build_dir.exists():
                    subprocess.run(["rm", "-rf", "build"], capture_output=True)

                # Go back to parent directory
                os.chdir(train_dir)

            if dir_path.name == "0050":
                break

        # Store mean CVs for this number of repeats
        mean_cv_cpu_cycles.append(np.mean(cv_cpu_cycles_list))
        mean_cv_wall_clock.append(np.mean(cv_wall_clock_time_list))

    # Plot the results
    plt.figure(figsize=(10, 6))
    plt.plot(num_repeats_list, mean_cv_cpu_cycles, "o-", label="CPU Cycles")
    plt.plot(
        num_repeats_list, mean_cv_wall_clock, "s-", label="Wall Clock Time"
    )
    plt.xlabel("Number of Repeats")
    plt.ylabel("Mean CV (%)")
    plt.title("Mean CV vs Number of Repeats")
    plt.legend()
    plt.grid(True)
    plt.savefig("cv_vs_repeats_1_to_9.png")
    plt.show()


if __name__ == "__main__":
    process_directories()
