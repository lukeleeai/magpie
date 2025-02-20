import pandas as pd

# Load the CSV files
finetuned_df = pd.read_csv("logs/test/llm_eoc_finetuned1.csv")
baseline_df = pd.read_csv("logs/test/llm_eoc_baseline.csv")

# Merge the two DataFrames on the index column to get shared indices
merged_df = pd.merge(
    finetuned_df, baseline_df, on="index", suffixes=("_finetuned", "_baseline")
)

# Calculate speedup factors for both finetuned and baseline
mean_reference_time = (
    merged_df["reference_time_baseline"]
    + merged_df["reference_time_finetuned"]
) / 2
speedups_finetuned = mean_reference_time / merged_df["new_code_time_finetuned"]
speedups_baseline = mean_reference_time / merged_df["new_code_time_baseline"]

# Calculate min, mean, and max speedup for both models
min_speedup_finetuned = speedups_finetuned.min()
mean_speedup_finetuned = speedups_finetuned.mean()
max_speedup_finetuned = speedups_finetuned.max()

min_speedup_baseline = speedups_baseline.min()
mean_speedup_baseline = speedups_baseline.mean()
max_speedup_baseline = speedups_baseline.max()

# Output the results with comparison
print(f"{'Metric':<15} {'Finetuned':<15} {'Baseline':<15}")
print(f"{'-'*15} {'-'*15} {'-'*15}")
print(
    f"{'Min':<15} {min_speedup_finetuned:<15.2f} {min_speedup_baseline:<15.2f}"
)
print(
    f"{'Mean':<15} {mean_speedup_finetuned:<15.2f} {mean_speedup_baseline:<15.2f}"
)
print(
    f"{'Max':<15} {max_speedup_finetuned:<15.2f} {max_speedup_baseline:<15.2f}"
)

# Calculate the mean difference between the two reference times
differences = (
    merged_df["reference_time_baseline"]
    - merged_df["reference_time_finetuned"]
).abs()
# show the min, mean, and max differences
print("Min:", differences.min())
print("Mean:", differences.mean())
print("Max:", differences.max())
