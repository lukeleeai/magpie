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
    minisat_dir = Path("minisat").resolve()
    print("minisat_dir", minisat_dir)

    # Check if train directory exists
    if not minisat_dir.is_dir():
        print("minisat directory not found!")
        return

    os.chdir(minisat_dir)

    # Number of repeats to test
    num_repeats = 10  # Changed to 10 repeats
    warmup_runs = 3   # First 3 runs are warmup
    all_cpu_times = []
    mean_cv_cpu_cycles = []
    mean_cv_wall_clock = []

    for i in range(num_repeats):
        cv_cpu_cycles_list = []
        cv_wall_clock_time_list = []
    
        run_script_path = os.path.join(minisat_dir, "run_fixed.sh")
        print("run_script_path: ", run_script_path)
        if os.path.exists(run_script_path):
            output = run_script(run_script_path)
            print("output: ", output)
            if output:  
                stats = output.strip().split("\n")
                print(f"{i+1} / {num_repeats}")
                cpu_times = []
                for line in stats:
                    if "CPU time" in line:
                        time_str = line.split(":")[-1].strip().split()[0]
                        cpu_times.append(float(time_str))
                mean_cpu_time = sum(cpu_times) / len(cpu_times)
                all_cpu_times.append(mean_cpu_time)

    # Calculate statistics for all repeats
    if all_cpu_times:
        final_mean = np.mean(all_cpu_times)
        final_std = np.std(all_cpu_times)
        final_cv = (final_std / final_mean) * 100 if final_mean != 0 else 0
        print(f"\nStats for all {num_repeats} repeats:")
        print(f"CV: {final_cv:.2f}%")
        print(f"Mean CPU time: {final_mean:.2f}s")
        print(f"Standard deviation: {final_std:.2f}s")

        # Calculate statistics for post-warmup runs
        post_warmup_times = all_cpu_times[warmup_runs:]
        warmup_mean = np.mean(post_warmup_times)
        warmup_std = np.std(post_warmup_times)
        warmup_cv = (warmup_std / warmup_mean) * 100 if warmup_mean != 0 else 0
        print(f"\nStats for last {num_repeats - warmup_runs} repeats (ignoring first {warmup_runs} warmup runs):")
        print(f"CV: {warmup_cv:.2f}%")
        print(f"Mean CPU time: {warmup_mean:.2f}s")
        print(f"Min CPU time: {min(post_warmup_times):.2f}s")
        print(f"Max CPU time: {max(post_warmup_times):.2f}s")
        print(f"Standard deviation: {warmup_std:.2f}s")

    # Analyze combined results
    cv_cpu_times_list = []
    num_repeats_list = range(1, num_repeats + 1)
    if all_cpu_times:
        for i in num_repeats_list:
            cpu_times_array = np.array(all_cpu_times[:i])
            mean = cpu_times_array.mean()
            std_dev = cpu_times_array.std()
            cv = (std_dev / mean) * 100 if mean != 0 else 0
            cv_cpu_times_list.append(cv)
     
    # Create a figure with two subplots
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 6))

    # Plot 1: CV vs Number of Repeats
    ax1.plot(num_repeats_list, cv_cpu_times_list, "o-", label="CPU Times")
    ax1.axvline(x=warmup_runs, color='r', linestyle='--', label='Warmup cutoff')
    ax1.set_xlabel("Number of Repeats")
    ax1.set_ylabel("Mean CV (%)")
    ax1.set_title("Mean CV vs Number of Repeats")
    ax1.legend()
    ax1.grid(True)

    # Plot 2: Scatter plot of CPU times
    ax2.scatter(range(1, warmup_runs + 1), all_cpu_times[:warmup_runs], alpha=0.6, label='Warmup', color='orange')
    ax2.scatter(range(warmup_runs + 1, len(all_cpu_times) + 1), all_cpu_times[warmup_runs:], alpha=0.6, label='Measured')
    ax2.axvline(x=warmup_runs, color='r', linestyle='--', label='Warmup cutoff')
    ax2.set_xlabel("Repeat Number")
    ax2.set_ylabel("CPU Time (s)")
    ax2.set_title("CPU Times Distribution")
    ax2.legend()
    ax2.grid(True)

    plt.tight_layout()
    plt.savefig("minisat_analysis.png")
    plt.show()


if __name__ == "__main__":
    process_directories()
