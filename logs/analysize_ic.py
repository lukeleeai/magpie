import pandas as pd
import matplotlib.pyplot as plt
# Load the CSV files
df = pd.read_csv("logs/train/llm_eoc_ic.csv")
speedups = df["reference_time"] / df["new_code_time"]

# # Plot the speedups in a histogram
# plt.hist(speedups, bins=20, edgecolor="black")
# plt.xlabel("Speedup")
# plt.ylabel("Frequency")
# plt.title("Histogram of Speedups")
# plt.show()

# Print the min, mean, max, and median of the speedups
print(f"Min: {speedups.min()}")
print(f"Mean: {speedups.mean()}")
print(f"Max: {speedups.max()}")
print(f"Median: {speedups.median()}")

# Get the top 5 speedups
top_speedups = speedups.nlargest(20)
print(top_speedups)

for index, row in df.iloc[top_speedups.index].iterrows():
    print(row["index"])
    print(row["new_code"])
    print(row["reference_time"] / row["new_code_time"])
    print("--------------------------------")

# max_speedup_code = df.iloc[max_speedup_index]["new_code"]
# max_speedup_index = df.iloc[max_speedup_index]["index"]

# print(f"Max speedup code: {max_speedup_code}")
# print(f"Max speedup index: {max_speedup_index}")
