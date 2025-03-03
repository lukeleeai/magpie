import os
import subprocess
from pathlib import Path
import numpy as np
import matplotlib.pyplot as plt
import logging
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
from scipy.stats import spearmanr

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


def get_stats(code_ids, num_repeats_list=[10]):
    # Save original directory
    original_dir = os.getcwd()
    
    # Get the train directory
    code_dir = Path("dataset/instruction_count_analysis/codes").resolve()
    print("Code_dir: ", code_dir)

    # Check if train directory exists
    if not code_dir.is_dir():
        print("Code directory not found!")
        return

    # Number of repeats to test
    mean_cv_cpu_cycles = []
    mean_cv_wall_clock = []
    mean_cv_instructions = []
    instruction_counts = {}

    for num_repeats in num_repeats_list:
        cv_cpu_cycles_list = []  # List to store CVs for each directory
        cv_wall_clock_time_list = []  # List to store CVs for each directory
        cv_instructions_list = []  # List to store CVs for each directory

        # Loop through all numbered directories from 0001 to 0020
        # dir_patterns = [f"{i:04d}" for i in range(1, 10)]
        # for dir_path in sorted(code_dir.glob(dir_patterns[0])) + sum([sorted(code_dir.glob(pattern)) for pattern in dir_patterns[1:]], []):
        for code_id in code_ids:
            dir_path = code_dir / code_id
            print("dir_path: ", dir_path)
            if dir_path.is_dir():
                try:
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
                    code_cpu_cycles = []
                    code_wall_clock_time = []
                    code_instructions = []
                    for i in range(num_repeats):
                        run_script_path = Path("run.sh")
                        if run_script_path.exists():
                            output = run_script(run_script_path)
                            if output:
                                stats = output.strip().split("\n")
                                print("stats: ", stats)
                                if len(stats[0]) == 0:
                                    print("No stats found for ", code_id)
                                    continue
                                cpu_cycles = [
                                    int(x.split()[0].replace(",", ""))
                                    for x in stats
                                ]
                                wall_clock_time = [
                                    float(x.split()[1]) for x in stats
                                ]
                                instructions = [
                                    int(x.split()[2].replace(",", "")) for x in stats
                                ]
                                code_cpu_cycles.extend(cpu_cycles)
                                code_wall_clock_time.extend(wall_clock_time)
                                code_instructions.extend(instructions)
                    instruction_counts[code_id] = np.mean(code_instructions)

                    # Analyze combined results
                    def compute_cv(array):
                        if array:
                            array_mean = np.mean(array)
                            array_std_dev = np.std(array)
                            cv = (array_std_dev / array_mean) * 100 if array_mean != 0 else 0
                            return cv
                        return 0

                    if code_cpu_cycles:
                        cv_cpu_cycles_list.append(compute_cv(code_cpu_cycles))

                    if code_wall_clock_time:
                        cv_wall_clock_time_list.append(compute_cv(code_wall_clock_time))

                    if code_instructions:
                        cv_instructions_list.append(compute_cv(code_instructions))

                    # Cleanup
                    if build_dir.exists():
                        subprocess.run(["rm", "-rf", "build"], capture_output=True)

                finally:
                    # Always return to original directory
                    os.chdir(original_dir)

            if dir_path.name == "0050":
                break

        # Store mean CVs for this number of repeats
        mean_cv_cpu_cycles.append(np.mean(cv_cpu_cycles_list))
        mean_cv_wall_clock.append(np.mean(cv_wall_clock_time_list))
        mean_cv_instructions.append(np.mean(cv_instructions_list))

    # Plot the results
    plt.figure(figsize=(10, 6))
    plt.plot(num_repeats_list, mean_cv_cpu_cycles, "o-", label="CPU Cycles")
    plt.plot(
        num_repeats_list, mean_cv_wall_clock, "s-", label="Wall Clock Time"
    )
    plt.plot(
        num_repeats_list, mean_cv_instructions, ":", label="Instructions"
    )
    plt.xlabel("Number of Repeats")
    plt.ylabel("Mean CV (%)")
    plt.title("Mean CV vs Number of Repeats")
    plt.legend()
    plt.grid(True)
    # plt.savefig("cv_vs_repeats_1_to_9.png")
    # plt.show()

    print("Mean CVs: ", mean_cv_cpu_cycles, mean_cv_wall_clock, mean_cv_instructions)
    return instruction_counts



if __name__ == "__main__":
    # Save original directory
    original_dir = os.getcwd()
    
    dir = "dataset/instruction_count_analysis"
    
    # df = pd.read_csv(f"{dir}/df.csv")

    # print("Number of problem ids with multiple codes: ", len(df["problem_id"].unique()))

    # code_ids = df["id"].tolist()
    # instruction_counts = get_stats(code_ids)
    # print("instruction_counts: ", instruction_counts)
    
    # # Make sure we're in the original directory
    # os.chdir(original_dir)
    
    # # save the instruction_counts to a csv file
    # df["instruction_count"] = df["id"].map(instruction_counts)
    # df.to_csv(f"{dir}/df_with_instruction_counts.csv", index=False)

    df = pd.read_csv(f"{dir}/df_with_instruction_counts.csv")

    print("Number of rows in df: ", len(df))
    # drop any rows where there is no instruction count
    df = df[df["instruction_count"].notna()]
    print("Number of rows in df after dropping rows with no instruction count: ", len(df))

    r2_scores = []

    problem_ids = df["problem_id"].unique()
    for problem_id in problem_ids:
        df_problem = df[df["problem_id"] == problem_id]
        instruction_counts = df_problem["instruction_count"].to_numpy()
        runtimes = df_problem["agg_runtime"].to_numpy()

        # Create a linear regression model
        model = LinearRegression()
        model.fit(instruction_counts.reshape(-1, 1), runtimes)

        # Get the predicted runtimes
        y_pred = model.predict(instruction_counts.reshape(-1, 1))

        # Calculate the MSE and R-squared score
        mse = mean_squared_error(runtimes, y_pred)
        r2 = r2_score(runtimes, y_pred)
        r2_scores.append(r2)

        print(f"Problem ID: {problem_id}")
        print(f"Mean Squared Error: {mse}")
        print(f"R-squared Score: {r2}")
        print("--------------------------------")
    
    print("Mean R-squared Score: ", np.mean(r2_scores))
    print("Min R-squared Score: ", np.min(r2_scores))
    print("Max R-squared Score: ", np.max(r2_scores))
    print("Median R-squared Score: ", np.median(r2_scores))
    print("Std Dev R-squared Score: ", np.std(r2_scores))

    # Plot the r2 scores
    plt.figure(figsize=(10, 6))
    plt.plot(r2_scores, "o-")
    plt.xlabel("Problem ID")
    plt.ylabel("R-squared Score")
    plt.title("R-squared Score for Each Problem ID")
    plt.show()

    # Plot instruction count vs runtime
    instruction_counts = df["instruction_count"].to_numpy()
    runtimes = df["agg_runtime"].to_numpy()
    plt.figure(figsize=(10, 6))
    plt.scatter(instruction_counts, runtimes, alpha=0.5)
    plt.xlabel("Instruction Count")
    plt.ylabel("Runtime")
    plt.title("Instruction Count vs Runtime")
    plt.show()

    # Now in log log
    plt.figure(figsize=(10, 6))
    plt.scatter(np.log(instruction_counts), np.log(runtimes), alpha=0.5)
    plt.xlabel("Log Instruction Count")
    plt.ylabel("Log Runtime")
    plt.title("Log Instruction Count vs Log Runtime")
    plt.show()

    spearman_correlations = []
    spearman_pvalues = []

    for problem_id in problem_ids:
        df_problem = df[df["problem_id"] == problem_id]
        instruction_counts = df_problem["instruction_count"].to_numpy()
        runtimes = df_problem["agg_runtime"].to_numpy()
        
        # Calculate Spearman correlation
        correlation, pvalue = spearmanr(instruction_counts, runtimes)
        spearman_correlations.append(correlation)
        spearman_pvalues.append(pvalue)
        
        print(f"Problem ID: {problem_id}")
        print(f"Spearman Correlation: {correlation:.3f}")
        print(f"P-value: {pvalue:.3e}")
        print("--------------------------------")
    
    print("\nSpearman Correlation Statistics:")
    print(f"Mean Correlation: {np.mean(spearman_correlations):.3f}")
    print(f"Median Correlation: {np.median(spearman_correlations):.3f}")
    print(f"Min Correlation: {np.min(spearman_correlations):.3f}")
    print(f"Max Correlation: {np.max(spearman_correlations):.3f}")
    print(f"Std Dev Correlation: {np.std(spearman_correlations):.3f}")

    print("Percentage of problems with Spearman correlation > 0.7: ", np.sum(np.array(spearman_correlations) > 0.7) / len(spearman_correlations))
    
    # Plot distribution of Spearman correlations
    plt.figure(figsize=(10, 6))
    plt.hist(spearman_correlations, bins=20, edgecolor='black')
    plt.xlabel("Spearman Correlation")
    plt.ylabel("Count")
    plt.title("Distribution of Spearman Correlations Across Problems")
    plt.show()

    # Create percentage above threshold plot
    thresholds = np.linspace(0, 1, 100)  # Create 100 points between 0 and 1
    percentages = [
        (np.sum(np.array(spearman_correlations) > threshold) / len(spearman_correlations)) * 100
        for threshold in thresholds
    ]
    
    plt.figure(figsize=(10, 6))
    plt.plot(thresholds, percentages, 'b-', linewidth=2)
    plt.grid(True, linestyle='--', alpha=0.7)
    plt.xlabel("Spearman Correlation Threshold")
    plt.ylabel("Percentage of Problems Above Threshold (%)")
    plt.title("Percentage of Problems Above Spearman Correlation Threshold")
    
    # Add some specific threshold annotations
    key_thresholds = [0.5, 0.6, 0.7, 0.8, 0.9]
    for threshold in key_thresholds:
        percentage = np.sum(np.array(spearman_correlations) > threshold) / len(spearman_correlations) * 100
        plt.plot([threshold, threshold], [0, percentage], 'r--', alpha=0.5)
        plt.plot([0, threshold], [percentage, percentage], 'r--', alpha=0.5)
        plt.annotate(f'{percentage:.1f}% above {threshold}',
                    xy=(threshold, percentage),
                    xytext=(threshold + 0.05, percentage + 5),
                    arrowprops=dict(facecolor='black', shrink=0.05),
                    )
    
    plt.show()
