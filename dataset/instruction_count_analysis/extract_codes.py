import pandas as pd
from dataset.build_pie_dataset import generate_data
import numpy as np

train_df = pd.read_json("dataset/train_hq_only.jsonl", lines=True)

# get the most common problem_id
problem_id_counts = train_df["problem_id"].value_counts()  # max 4

# get the problem_ids with more than 1 code
problem_ids_with_multiple_codes = problem_id_counts[
    problem_id_counts > 3
].index.tolist()[:100]

print(
    "number of problem_ids with multiple codes: ",
    len(problem_ids_with_multiple_codes),
)

df = pd.DataFrame()

for problem_id in problem_ids_with_multiple_codes:
    # get the rows where problem_id is the most common problem_id
    # src_columns = ["problem_id", "src_id", "src_agg_runtime", "src_code"]
    # tgt_columns = ["problem_id", "tgt_id", "tgt_agg_runtime", "tgt_code"]

    src_columns = ["problem_id", "src_id", "src_agg_runtime", "src_code"]
    tgt_columns = ["problem_id", "tgt_id", "tgt_agg_runtime", "tgt_code"]
    src_df = train_df[train_df["problem_id"] == problem_id][src_columns]
    tgt_df = train_df[train_df["problem_id"] == problem_id][tgt_columns]

    # remove "src_" and "tgt_" from the column names
    src_df.columns = src_df.columns.str.replace("src_", "")
    tgt_df.columns = tgt_df.columns.str.replace("tgt_", "")

    # merge the dataframes into a single dataframe (longer dataframe)
    df = pd.concat([df, src_df, tgt_df], ignore_index=True)

df.to_csv("dataset/instruction_count_analysis/df.csv", index=False)

# Build the dataset using automate.py
for index, row in df.iterrows():
    generate_data(
        row,
        index,
        data_dir=f"dataset/instruction_count_analysis/codes/{row['id']}",
    )

print("Total number of rows in df: ", len(df))
