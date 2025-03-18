from glob import glob
import pandas as pd

reflection_types = [
    "ALL",
    "MOST_SUCCESSFUL",
    "NONE",
]

df = pd.DataFrame()

for reflection_type in reflection_types:
    # print(f"Reflection type: {reflection_type}")
    for i in range(1, 5):
        # print(f"Reflection type: {reflection_type}, Generation: {i}")
        for log_file_dir in glob(f"logs/codes/*{reflection_type}*{i}/*.txt"):
            log_filename = log_file_dir.split("/")[-1]
            fitness = log_filename.split("_")[0]
            if fitness.endswith(".txt"):
                continue
            df = df._append({"fitness": fitness, "reflection_type": reflection_type, "generation": i}, ignore_index=True)

for reflection_type in reflection_types:
    print(f"Reflection type: {reflection_type}")
    # % of "failed" in fitness
    failed_percentage = df[df["reflection_type"] == reflection_type]["fitness"].value_counts()["failed"] / len(df[df["reflection_type"] == reflection_type])
    print(f"Failed percentage: {failed_percentage:.2%}")
    # Now, remove "failed" from df
    successful_df = df[df["reflection_type"] == reflection_type][df["fitness"] != "failed"]
    successful_df["fitness"] = successful_df["fitness"].astype(float)
    min_fitness = successful_df["fitness"].min()
    max_fitness = successful_df["fitness"].max()
    mean_fitness = successful_df["fitness"].mean()
    median_fitness = successful_df["fitness"].median()
    print(f"Min fitness: {min_fitness}")
    print(f"Max fitness: {max_fitness}")
    print(f"Mean fitness: {mean_fitness}")

