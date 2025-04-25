import os
import re
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from tabulate import tabulate
import hashlib
from scipy.stats import mannwhitneyu, ttest_ind  # Add import for statistical testing

# Suppress specific SettingWithCopyWarning
pd.options.mode.chained_assignment = None

# --- Configuration ---
LOG_DIR = "logs"
if not os.path.isdir(LOG_DIR):
    raise FileNotFoundError(f"Log directory '{LOG_DIR}' not found.")
DATASETS = ["sat4j", "minisat"]
ALGORITHMS = ["gp", "sbco_agent_no_reflection", "sbco_agent_reflection_on_all", "sbco_agent_reflection_on_successful"]
MAX_STEPS = 200

# --- Data Loading ---
all_data = []
processed_seeds = set()
repeat_percentages = []

print("--- Starting Data Loading ---")
for dataset in DATASETS:
    print(f"Processing Dataset: {dataset}")
    for algorithm in ALGORITHMS:
        processed_seed_count = 0  # Initialize a counter for processed seeds per algorithm
        log_dir_alg = os.path.join(LOG_DIR, dataset, algorithm)
        if not os.path.exists(log_dir_alg):
            print(f"  Warning: Algorithm directory not found, skipping: {log_dir_alg}")
            continue

        seeds = os.listdir(log_dir_alg)
        print(f"  Processing Algorithm: {algorithm} ({len(seeds)} potential seeds found)")

        for seed in seeds:
            if processed_seed_count >= 20:
                break  # Stop processing if the limit of 12 seeds is reached
            seed_dir = os.path.join(log_dir_alg, seed)
            if not os.path.isdir(seed_dir):
                continue

            log_files = sorted([f for f in os.listdir(seed_dir) if f.endswith('.txt')])
            if not log_files:
                continue

            # First pass: Collect data to determine baseline_best_score
            temp_seed_data = []
            code_hashes = set()
            total_patches = 0
            duplicate_patches = 0

            for file in log_files:
                pattern = r'step(\d+)_run(.+?)_best([\d.]+)\.txt'
                match = re.match(pattern, file)
                if match:
                    step = int(match.group(1))
                    run_result_str = match.group(2)
                    filename_best = float(match.group(3))

                    if step > MAX_STEPS:
                        continue

                    # Read the content of the file to hash the code
                    file_path = os.path.join(seed_dir, file)
                    try:
                        with open(file_path, 'r', encoding='utf-8') as f:
                            code_content = f.read()
                        # Strip whitespace, remove comments, and normalize line endings before hashing
                        normalized_lines = []
                        for line in code_content.splitlines():
                            # Remove comments (assume # for Python-style comments)
                            line = line.split('#')[0]
                            # Remove // style comments (for C-style languages)
                            line = line.split('//')[0]
                            # Strip whitespace
                            line = line.strip()
                            # Only add non-empty lines
                            if line:
                                normalized_lines.append(line)
                        normalized_content = '\n'.join(normalized_lines)
                        code_hash = hashlib.md5(normalized_content.encode('utf-8')).hexdigest()
                    except Exception as e:
                        print(f"    Warning: Could not read file {file_path} for hashing: {e}")
                        code_hash = None

                    total_patches += 1
                    if code_hash:
                        if code_hash in code_hashes:
                            duplicate_patches += 1
                        else:
                            code_hashes.add(code_hash)

                    run_result_type = 'other'
                    run_result_val = np.nan
                    try:
                        run_result_val = float(run_result_str)
                        run_result_type = 'success'
                    except ValueError:
                        if run_result_str == 'TEST_CODE_ERROR':
                            run_result_type = 'test_error'
                        elif run_result_str == 'COMPILE_CODE_ERROR':
                            run_result_type = 'compile_error'

                    temp_seed_data.append({
                        "dataset": dataset,
                        "algorithm": algorithm,
                        "seed": seed,
                        "step": step,
                        "run_result_str": run_result_str,
                        "run_result_val": run_result_val,
                        "run_result_type": run_result_type,
                        "filename_best": filename_best,
                        "code_hash": code_hash
                    })

            # Calculate baseline_best_score
            if temp_seed_data:
                seed_df_temp = pd.DataFrame(temp_seed_data).sort_values('step')
                first_success_run = seed_df_temp[seed_df_temp['run_result_type'] == 'success'].iloc[0] if not seed_df_temp[seed_df_temp['run_result_type'] == 'success'].empty else None
                baseline_score = first_success_run['filename_best'] if first_success_run is not None else np.nan

                # Second pass: Add baseline_best_score to each dictionary
                seed_data = []
                for row in temp_seed_data:
                    row['baseline_best_score'] = baseline_score
                    seed_data.append(row)

                all_data.extend(seed_data)
                processed_seeds.add((dataset, algorithm, seed))
                processed_seed_count += 1  # Increment the counter after processing a seed

                # Calculate percentage of repeated variants for this seed
                if total_patches > 0:
                    repeat_percentage = (duplicate_patches / total_patches) * 100
                else:
                    repeat_percentage = 0.0
                repeat_percentages.append({
                    'Dataset': dataset,
                    'Algorithm': algorithm,
                    'Seed': seed,
                    'Repeat %': repeat_percentage
                })

print(f"--- Data Loading Complete. Processed {len(processed_seeds)} unique seeds. ---")

# --- Data Processing ---
if not all_data:
    print("Error: No data loaded from logs. Exiting.")
    exit()

df = pd.DataFrame(all_data)
df['step'] = df['step'].astype(int)
df['filename_best'] = df['filename_best'].astype(float)
df['baseline_best_score'] = df['baseline_best_score'].astype(float)
df['run_result_val'] = df['run_result_val'].astype(float)

# Calculate Improvement Percentage
df['improvement_pct'] = np.nan
valid_baseline_mask = ~df['baseline_best_score'].isna() & (df['baseline_best_score'] != 0)
df.loc[valid_baseline_mask, 'improvement_pct'] = \
    (df['baseline_best_score'] - df['filename_best']) / df['baseline_best_score'] * 100
zero_baseline_mask = df['baseline_best_score'] == 0
df.loc[zero_baseline_mask & (df['filename_best'] == 0), 'improvement_pct'] = 0.0
df.loc[zero_baseline_mask & (df['filename_best'] != 0), 'improvement_pct'] = np.nan

# --- Analysis and Aggregation ---
outcome_summary_list = []
overall_improvement_summary_list = []
percentile_improvement_summary_list = []
repeat_summary_list = []

# Define percentiles first
percentiles = [0.2, 0.4, 0.6, 0.8, 1.0]
target_steps = {int(p*100): int(MAX_STEPS * p) for p in percentiles}

# Dictionary to store raw data for t-tests
algorithm_improvement_data = {dataset: {algo: [] for algo in ALGORITHMS} for dataset in DATASETS}
# Add additional data structures for other metrics
algorithm_success_rates = {dataset: {algo: [] for algo in ALGORITHMS} for dataset in DATASETS}
algorithm_test_error_rates = {dataset: {algo: [] for algo in ALGORITHMS} for dataset in DATASETS}
algorithm_compile_error_rates = {dataset: {algo: [] for algo in ALGORITHMS} for dataset in DATASETS}
algorithm_repeat_rates = {dataset: {algo: [] for algo in ALGORITHMS} for dataset in DATASETS}
algorithm_percentile_improvements = {dataset: {algo: {p: [] for p in percentiles} for algo in ALGORITHMS} for dataset in DATASETS}

print("\n--- Starting Analysis ---")

for dataset in DATASETS:
    print(f"\nAnalyzing Dataset: {dataset}")
    dataset_df = df[df['dataset'] == dataset]
    if dataset_df.empty: continue

    for algorithm in ALGORITHMS:
        print(f"  Analyzing Algorithm: {algorithm}")
        alg_df = dataset_df[dataset_df['algorithm'] == algorithm]
        if alg_df.empty: continue

        unique_seeds = alg_df['seed'].unique()
        print(f"    Found {len(unique_seeds)} seeds for this algorithm.")

        seed_success_rates = []
        seed_test_error_rates = []
        seed_compile_error_rates = []
        seed_overall_max_improvements = []
        seed_improvements_at_target_steps = {p: [] for p in target_steps.keys()}
        seed_repeat_rates = []

        for seed in unique_seeds:
            seed_df = alg_df[alg_df['seed'] == seed].sort_values('step')
            if seed_df.empty: continue

            total_runs = len(seed_df)
            if total_runs == 0: continue

            # Outcome Rates
            success_count = (seed_df['run_result_type'] == 'success').sum()
            test_error_count = (seed_df['run_result_type'] == 'test_error').sum()
            compile_error_count = (seed_df['run_result_type'] == 'compile_error').sum()
            success_rate = success_count / total_runs * 100
            test_error_rate = test_error_count / total_runs * 100
            compile_error_rate = compile_error_count / total_runs * 100
            
            seed_success_rates.append(success_rate)
            seed_test_error_rates.append(test_error_rate)
            seed_compile_error_rates.append(compile_error_rate)
            
            # Store raw data for t-tests
            algorithm_success_rates[dataset][algorithm].append(success_rate)
            algorithm_test_error_rates[dataset][algorithm].append(test_error_rate)
            algorithm_compile_error_rates[dataset][algorithm].append(compile_error_rate)

            # Improvement Calculations
            if not pd.isna(seed_df['baseline_best_score']).all():
                seed_df['cumulative_max_improvement_pct'] = seed_df['improvement_pct'].fillna(float('-inf')).cummax()
                seed_df.loc[seed_df['cumulative_max_improvement_pct'] == float('-inf'), 'cumulative_max_improvement_pct'] = np.nan

                overall_max_imp = seed_df['cumulative_max_improvement_pct'].max()
                if not pd.isna(overall_max_imp):
                    seed_overall_max_improvements.append(overall_max_imp)
                    algorithm_improvement_data[dataset][algorithm].append(overall_max_imp)

                for p_key, target_step in target_steps.items():
                    imp_at_target = seed_df[seed_df['step'] <= target_step]['cumulative_max_improvement_pct'].iloc[-1] if not seed_df[seed_df['step'] <= target_step].empty else np.nan
                    if not pd.isna(imp_at_target):
                        seed_improvements_at_target_steps[p_key].append(imp_at_target)
                        # Store raw data for percentile t-tests (p_key is like 20, 40, etc.)
                        percentile_idx = list(target_steps.keys()).index(p_key)
                        p_value = percentiles[percentile_idx]
                        algorithm_percentile_improvements[dataset][algorithm][p_value].append(imp_at_target)

            # Get the repeat percentage for this seed
            seed_repeat_df = pd.DataFrame(repeat_percentages)
            seed_repeat_rate = seed_repeat_df[
                (seed_repeat_df['Dataset'] == dataset) &
                (seed_repeat_df['Algorithm'] == algorithm) &
                (seed_repeat_df['Seed'] == seed)
            ]['Repeat %'].iloc[0] if not seed_repeat_df[
                (seed_repeat_df['Dataset'] == dataset) &
                (seed_repeat_df['Algorithm'] == algorithm) &
                (seed_repeat_df['Seed'] == seed)
            ].empty else np.nan
            if not pd.isna(seed_repeat_rate):
                seed_repeat_rates.append(seed_repeat_rate)
                algorithm_repeat_rates[dataset][algorithm].append(seed_repeat_rate)

        # Aggregate Results
        outcome_summary_list.append({
            'Dataset': dataset, 'Algorithm': algorithm,
            'Success %': np.median(seed_success_rates) if seed_success_rates else np.nan,
            'Test Error %': np.median(seed_test_error_rates) if seed_test_error_rates else np.nan,
            'Compile Error %': np.median(seed_compile_error_rates) if seed_compile_error_rates else np.nan,
        })

        overall_improvement_summary_list.append({
            'Dataset': dataset, 'Algorithm': algorithm,
            'Min Improvement %': np.min(seed_overall_max_improvements) if seed_overall_max_improvements else np.nan,
            'Median Improvement %': np.median(seed_overall_max_improvements) if seed_overall_max_improvements else np.nan,
            'Max Improvement %': np.max(seed_overall_max_improvements) if seed_overall_max_improvements else np.nan,
        })

        percentile_row = {'Dataset': dataset, 'Algorithm': algorithm}
        for p_key, imp_list in seed_improvements_at_target_steps.items():
            median_imp = np.median(imp_list) if imp_list else np.nan
            percentile_row[f'Median Improvement % ({p_key}%)'] = median_imp
        percentile_improvement_summary_list.append(percentile_row)

        # Aggregate Repeat Percentages with Min, Median, Max
        repeat_summary_list.append({
            'Dataset': dataset, 'Algorithm': algorithm,
            'Min Repeat %': np.min(seed_repeat_rates) if seed_repeat_rates else np.nan,
            'Median Repeat %': np.median(seed_repeat_rates) if seed_repeat_rates else np.nan,
            'Max Repeat %': np.max(seed_repeat_rates) if seed_repeat_rates else np.nan,
        })

print("--- Analysis Complete ---")

# --- Display Summary Tables ---
print("\n--- Generating Summary Tables ---")
outcome_summary_df = pd.DataFrame(outcome_summary_list)
overall_improvement_summary_df = pd.DataFrame(overall_improvement_summary_list)
percentile_improvement_summary_df = pd.DataFrame(percentile_improvement_summary_list)
repeat_summary_df = pd.DataFrame(repeat_summary_list)

# --- Statistical Testing ---
print("\n--- Statistical Testing (Mann-Whitney U tests) ---")

# Define a function to perform Mann-Whitney U test between two algorithms
def perform_test(data1, data2):
    if len(data1) > 0 and len(data2) > 0:
        try:
            # Use Mann-Whitney U test (more appropriate for comparing medians)
            u_stat, p_value = mannwhitneyu(data1, data2, alternative='two-sided')
            return u_stat, p_value, np.median(data1), np.median(data2)
        except ValueError as e:
            # Handle cases where the test can't be performed (e.g., identical distributions)
            print(f"  Warning: Mann-Whitney U test failed: {e}")
            return np.nan, np.nan, np.median(data1), np.median(data2)
    return np.nan, np.nan, np.nan, np.nan

# Perform Mann-Whitney U tests between algorithms for all metrics
improvement_test_results = []
success_rate_test_results = []
test_error_rate_test_results = []
compile_error_rate_test_results = []
repeat_rate_test_results = []
percentile_test_results = {p: [] for p in percentiles}

for dataset in DATASETS:
    for i, algo1 in enumerate(ALGORITHMS):
        for algo2 in ALGORITHMS[i+1:]:  # Compare each algorithm with others that come after it
            # Overall improvement test
            imp_data1 = algorithm_improvement_data[dataset][algo1]
            imp_data2 = algorithm_improvement_data[dataset][algo2]
            u_stat, p_value, median1, median2 = perform_test(imp_data1, imp_data2)
            improvement_test_results.append({
                'Dataset': dataset,
                'Algorithm 1': algo1,
                'Algorithm 2': algo2,
                'Algorithm 1 Median': median1,
                'Algorithm 2 Median': median2,
                'U-statistic': u_stat,
                'P-value': p_value,
                'Significant': p_value < 0.05 if not pd.isna(p_value) else False
            })
            
            # Success rate test
            success_data1 = algorithm_success_rates[dataset][algo1]
            success_data2 = algorithm_success_rates[dataset][algo2]
            u_stat, p_value, median1, median2 = perform_test(success_data1, success_data2)
            success_rate_test_results.append({
                'Dataset': dataset,
                'Algorithm 1': algo1,
                'Algorithm 2': algo2,
                'Algorithm 1 Median': median1,
                'Algorithm 2 Median': median2,
                'U-statistic': u_stat,
                'P-value': p_value,
                'Significant': p_value < 0.05 if not pd.isna(p_value) else False
            })
            
            # Test error rate test
            test_error_data1 = algorithm_test_error_rates[dataset][algo1]
            test_error_data2 = algorithm_test_error_rates[dataset][algo2]
            u_stat, p_value, median1, median2 = perform_test(test_error_data1, test_error_data2)
            test_error_rate_test_results.append({
                'Dataset': dataset,
                'Algorithm 1': algo1,
                'Algorithm 2': algo2,
                'Algorithm 1 Median': median1,
                'Algorithm 2 Median': median2,
                'U-statistic': u_stat,
                'P-value': p_value,
                'Significant': p_value < 0.05 if not pd.isna(p_value) else False
            })
            
            # Compile error rate test
            compile_error_data1 = algorithm_compile_error_rates[dataset][algo1]
            compile_error_data2 = algorithm_compile_error_rates[dataset][algo2]
            u_stat, p_value, median1, median2 = perform_test(compile_error_data1, compile_error_data2)
            compile_error_rate_test_results.append({
                'Dataset': dataset,
                'Algorithm 1': algo1,
                'Algorithm 2': algo2,
                'Algorithm 1 Median': median1,
                'Algorithm 2 Median': median2,
                'U-statistic': u_stat,
                'P-value': p_value,
                'Significant': p_value < 0.05 if not pd.isna(p_value) else False
            })
            
            # Repeat rate test
            repeat_data1 = algorithm_repeat_rates[dataset][algo1]
            repeat_data2 = algorithm_repeat_rates[dataset][algo2]
            u_stat, p_value, median1, median2 = perform_test(repeat_data1, repeat_data2)
            repeat_rate_test_results.append({
                'Dataset': dataset,
                'Algorithm 1': algo1,
                'Algorithm 2': algo2,
                'Algorithm 1 Median': median1,
                'Algorithm 2 Median': median2,
                'U-statistic': u_stat,
                'P-value': p_value,
                'Significant': p_value < 0.05 if not pd.isna(p_value) else False
            })
            
            # Percentile improvement tests
            for p in percentiles:
                percentile_data1 = algorithm_percentile_improvements[dataset][algo1][p]
                percentile_data2 = algorithm_percentile_improvements[dataset][algo2][p]
                u_stat, p_value, median1, median2 = perform_test(percentile_data1, percentile_data2)
                percentile_test_results[p].append({
                    'Dataset': dataset,
                    'Algorithm 1': algo1,
                    'Algorithm 2': algo2,
                    'Algorithm 1 Median': median1,
                    'Algorithm 2 Median': median2,
                    'U-statistic': u_stat,
                    'P-value': p_value,
                    'Significant': p_value < 0.05 if not pd.isna(p_value) else False,
                    'Percentile': int(p * 100)
                })

# Convert to DataFrames
improvement_test_df = pd.DataFrame(improvement_test_results)
success_rate_test_df = pd.DataFrame(success_rate_test_results)
test_error_rate_test_df = pd.DataFrame(test_error_rate_test_results)
compile_error_rate_test_df = pd.DataFrame(compile_error_rate_test_results)
repeat_rate_test_df = pd.DataFrame(repeat_rate_test_results)
percentile_test_dfs = {p: pd.DataFrame(percentile_test_results[p]) for p in percentiles}

algo_name_map = {
    "gp": "GP", "sbco_agent_no_reflection": "SBCO-NoReflect",
    "sbco_agent_reflection_on_all": "SBCO-ReflectAll",
    "sbco_agent_reflection_on_successful": "SBCO-ReflectSuccess"
}
def map_algo_name(name): return algo_name_map.get(name, name)

TABLE_FORMAT = "pipe"

for dataset in DATASETS:
    print(f"\n\n=== SUMMARY TABLES: {dataset} ===")

    ds_outcome_summary = outcome_summary_df[outcome_summary_df['Dataset'] == dataset].copy()
    ds_overall_imp_summary = overall_improvement_summary_df[overall_improvement_summary_df['Dataset'] == dataset].copy()
    ds_percentile_imp_summary = percentile_improvement_summary_df[percentile_improvement_summary_df['Dataset'] == dataset].copy()
    ds_repeat_summary = repeat_summary_df[repeat_summary_df['Dataset'] == dataset].copy()
    
    # Filter test results for this dataset
    ds_improvement_test = improvement_test_df[improvement_test_df['Dataset'] == dataset].copy()
    ds_success_rate_test = success_rate_test_df[success_rate_test_df['Dataset'] == dataset].copy()
    ds_test_error_rate_test = test_error_rate_test_df[test_error_rate_test_df['Dataset'] == dataset].copy()
    ds_compile_error_rate_test = compile_error_rate_test_df[compile_error_rate_test_df['Dataset'] == dataset].copy()
    ds_repeat_rate_test = repeat_rate_test_df[repeat_rate_test_df['Dataset'] == dataset].copy()
    ds_percentile_test = {p: percentile_test_dfs[p][percentile_test_dfs[p]['Dataset'] == dataset].copy() for p in percentiles}

    if ds_outcome_summary.empty and ds_overall_imp_summary.empty and ds_percentile_imp_summary.empty and ds_repeat_summary.empty:
        print(f"  No results to display for this dataset.")
        continue

    for df in [ds_outcome_summary, ds_overall_imp_summary, ds_percentile_imp_summary, ds_repeat_summary]:
        if not df.empty:
            df['Algorithm'] = df['Algorithm'].apply(map_algo_name)
    
    # Apply algorithm name mapping to test dataframes
    for df in [ds_improvement_test, ds_success_rate_test, ds_test_error_rate_test, 
              ds_compile_error_rate_test, ds_repeat_rate_test]:
        if not df.empty:
            df['Algorithm 1'] = df['Algorithm 1'].apply(map_algo_name)
            df['Algorithm 2'] = df['Algorithm 2'].apply(map_algo_name)
    
    for p in percentiles:
        if not ds_percentile_test[p].empty:
            ds_percentile_test[p]['Algorithm 1'] = ds_percentile_test[p]['Algorithm 1'].apply(map_algo_name)
            ds_percentile_test[p]['Algorithm 2'] = ds_percentile_test[p]['Algorithm 2'].apply(map_algo_name)

    # Table 1: Min, Median, Max Speedup Improvements
    print(f"\n1. Min, Median, Max Speedup Improvements (%):")
    if not ds_overall_imp_summary.empty:
        overall_imp_display = ds_overall_imp_summary.set_index('Algorithm')
        imp_cols = ['Min Improvement %', 'Median Improvement %', 'Max Improvement %']
        overall_imp_formatted = overall_imp_display[imp_cols].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
        overall_imp_formatted.columns = ['Min', 'Median', 'Max']
        print(tabulate(overall_imp_formatted, headers='keys', tablefmt=TABLE_FORMAT, stralign="center"))
        
        # Display test results for improvement
        print(f"\n1.1 Test Results for Improvement Comparisons:")
        if not ds_improvement_test.empty:
            test_display = ds_improvement_test.copy()
            test_display['Algorithm 1 Median'] = test_display['Algorithm 1 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
            test_display['Algorithm 2 Median'] = test_display['Algorithm 2 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
            test_display['U-statistic'] = test_display['U-statistic'].map(lambda x: f"{x:.3f}" if not pd.isna(x) else "N/A")
            test_display['P-value'] = test_display['P-value'].map(lambda x: f"{x:.4f}" if not pd.isna(x) else "N/A")
            test_display['Significant'] = test_display['Significant'].map(lambda x: "Yes" if x else "No")
            
            test_cols = ['Algorithm 1', 'Algorithm 2', 'Algorithm 1 Median', 'Algorithm 2 Median', 'U-statistic', 'P-value', 'Significant']
            print(tabulate(test_display[test_cols], headers='keys', tablefmt=TABLE_FORMAT, showindex=False, stralign="center"))
        else:
            print("  No test results available.")
    else:
        print("  No improvement data available.")

    # Table 2: Outcome Rates (Median only)
    print(f"\n2. Run Outcome Rates (% of total runs per seed, median across seeds):")
    if not ds_outcome_summary.empty:
        outcome_display = ds_outcome_summary.set_index('Algorithm')
        outcome_cols = ['Success %', 'Test Error %', 'Compile Error %']
        outcome_formatted = outcome_display[outcome_cols].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
        outcome_formatted.columns = ['Success %', 'Test Error %', 'Compile Error %']
        print(tabulate(outcome_formatted, headers='keys', tablefmt=TABLE_FORMAT, stralign="center"))
        
        # Display test results for success rate
        print(f"\n2.1 Test Results for Success Rate Comparisons:")
        if not ds_success_rate_test.empty:
            test_display = ds_success_rate_test.copy()
            test_display['Algorithm 1 Median'] = test_display['Algorithm 1 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
            test_display['Algorithm 2 Median'] = test_display['Algorithm 2 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
            test_display['U-statistic'] = test_display['U-statistic'].map(lambda x: f"{x:.3f}" if not pd.isna(x) else "N/A")
            test_display['P-value'] = test_display['P-value'].map(lambda x: f"{x:.4f}" if not pd.isna(x) else "N/A")
            test_display['Significant'] = test_display['Significant'].map(lambda x: "Yes" if x else "No")
            
            test_cols = ['Algorithm 1', 'Algorithm 2', 'Algorithm 1 Median', 'Algorithm 2 Median', 'U-statistic', 'P-value', 'Significant']
            print(tabulate(test_display[test_cols], headers='keys', tablefmt=TABLE_FORMAT, showindex=False, stralign="center"))
        else:
            print("  No test results available.")
            
        # Display test results for test error rate
        print(f"\n2.2 Test Results for Test Error Rate Comparisons:")
        if not ds_test_error_rate_test.empty:
            test_display = ds_test_error_rate_test.copy()
            test_display['Algorithm 1 Median'] = test_display['Algorithm 1 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
            test_display['Algorithm 2 Median'] = test_display['Algorithm 2 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
            test_display['U-statistic'] = test_display['U-statistic'].map(lambda x: f"{x:.3f}" if not pd.isna(x) else "N/A")
            test_display['P-value'] = test_display['P-value'].map(lambda x: f"{x:.4f}" if not pd.isna(x) else "N/A")
            test_display['Significant'] = test_display['Significant'].map(lambda x: "Yes" if x else "No")
            
            test_cols = ['Algorithm 1', 'Algorithm 2', 'Algorithm 1 Median', 'Algorithm 2 Median', 'U-statistic', 'P-value', 'Significant']
            print(tabulate(test_display[test_cols], headers='keys', tablefmt=TABLE_FORMAT, showindex=False, stralign="center"))
        else:
            print("  No test results available.")
            
        # Display test results for compile error rate
        print(f"\n2.3 Test Results for Compile Error Rate Comparisons:")
        if not ds_compile_error_rate_test.empty:
            test_display = ds_compile_error_rate_test.copy()
            test_display['Algorithm 1 Median'] = test_display['Algorithm 1 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
            test_display['Algorithm 2 Median'] = test_display['Algorithm 2 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
            test_display['U-statistic'] = test_display['U-statistic'].map(lambda x: f"{x:.3f}" if not pd.isna(x) else "N/A")
            test_display['P-value'] = test_display['P-value'].map(lambda x: f"{x:.4f}" if not pd.isna(x) else "N/A")
            test_display['Significant'] = test_display['Significant'].map(lambda x: "Yes" if x else "No")
            
            test_cols = ['Algorithm 1', 'Algorithm 2', 'Algorithm 1 Median', 'Algorithm 2 Median', 'U-statistic', 'P-value', 'Significant']
            print(tabulate(test_display[test_cols], headers='keys', tablefmt=TABLE_FORMAT, showindex=False, stralign="center"))
        else:
            print("  No test results available.")
    else:
        print("  No outcome rate data available.")

    # Table 3: Median Speedup at Step Percentiles
    print(f"\n3. Median Speedup Improvement % at Step Percentiles:")
    if not ds_percentile_imp_summary.empty:
        percentile_display = ds_percentile_imp_summary.set_index('Algorithm')
        percentile_cols = [f'Median Improvement % ({p}%)' for p in target_steps.keys()]
        percentile_formatted = percentile_display[percentile_cols].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
        percentile_formatted.columns = [f"{p}%" for p in target_steps.keys()]
        print(tabulate(percentile_formatted, headers='keys', tablefmt=TABLE_FORMAT, stralign="center"))
        
        # Display test results for each percentile
        for i, p in enumerate(percentiles):
            p_key = int(p * 100)
            print(f"\n3.{i+1} Test Results for {p_key}% Step Percentile Comparisons:")
            if not ds_percentile_test[p].empty:
                test_display = ds_percentile_test[p].copy()
                test_display['Algorithm 1 Median'] = test_display['Algorithm 1 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
                test_display['Algorithm 2 Median'] = test_display['Algorithm 2 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
                test_display['U-statistic'] = test_display['U-statistic'].map(lambda x: f"{x:.3f}" if not pd.isna(x) else "N/A")
                test_display['P-value'] = test_display['P-value'].map(lambda x: f"{x:.4f}" if not pd.isna(x) else "N/A")
                test_display['Significant'] = test_display['Significant'].map(lambda x: "Yes" if x else "No")
                
                test_cols = ['Algorithm 1', 'Algorithm 2', 'Algorithm 1 Median', 'Algorithm 2 Median', 'U-statistic', 'P-value', 'Significant']
                print(tabulate(test_display[test_cols], headers='keys', tablefmt=TABLE_FORMAT, showindex=False, stralign="center"))
            else:
                print("  No test results available.")
    else:
        print("  No percentile improvement data available.")

    # Table 4: Min, Median, Max Percentage of Repeated Variants
    print(f"\n4. Min, Median, Max Percentage of Repeated Variants (% of total patches per seed):")
    if not ds_repeat_summary.empty:
        repeat_display = ds_repeat_summary.set_index('Algorithm')
        repeat_cols = ['Min Repeat %', 'Median Repeat %', 'Max Repeat %']
        repeat_formatted = repeat_display[repeat_cols].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
        repeat_formatted.columns = ['Min', 'Median', 'Max']
        print(tabulate(repeat_formatted, headers='keys', tablefmt=TABLE_FORMAT, stralign="center"))
        
        # Display test results for repeat rates
        print(f"\n4.1 Test Results for Repeat Rate Comparisons:")
        if not ds_repeat_rate_test.empty:
            test_display = ds_repeat_rate_test.copy()
            test_display['Algorithm 1 Median'] = test_display['Algorithm 1 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
            test_display['Algorithm 2 Median'] = test_display['Algorithm 2 Median'].map(lambda x: f"{x:.1f}%" if not pd.isna(x) else "N/A")
            test_display['U-statistic'] = test_display['U-statistic'].map(lambda x: f"{x:.3f}" if not pd.isna(x) else "N/A")
            test_display['P-value'] = test_display['P-value'].map(lambda x: f"{x:.4f}" if not pd.isna(x) else "N/A")
            test_display['Significant'] = test_display['Significant'].map(lambda x: "Yes" if x else "No")
            
            test_cols = ['Algorithm 1', 'Algorithm 2', 'Algorithm 1 Median', 'Algorithm 2 Median', 'U-statistic', 'P-value', 'Significant']
            print(tabulate(test_display[test_cols], headers='keys', tablefmt=TABLE_FORMAT, showindex=False, stralign="center"))
        else:
            print("  No test results available.")
    else:
        print("  No repeat percentage data available.")

print("\n--- Script Finished ---")