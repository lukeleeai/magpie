# 1. read dataset/train_hq_only.jsonl (only the last 1000 lines)
# 2. extract src_code and tgt_code and the "speedup"
# 3. write to a new file dataset/pie_dataset.jsonl

import json
from pathlib import Path


def process_last_n_lines(input_file, output_file, n=1000):
    # Read the last n lines from the input file
    with open(input_file, "r") as f:
        lines = f.readlines()
        lines = lines[-n:]  # Get last n lines

    # Process each line and extract required fields
    processed_data = []
    for line in lines:
        entry = json.loads(line)

        # Create OpenAI fine-tuning format
        processed_entry = {
            "messages": [
                {
                    "role": "system",
                    "content": "You are a master of code optimization.",
                },
                {
                    "role": "user",
                    "content": f"// Slower version of the code: \n{entry['src_code']}",
                },
                {
                    "role": "assistant",
                    "content": f"// Faster version of the code (speedup: {entry['speedup']}): \n{entry['tgt_code']}",
                },
            ]
        }
        processed_data.append(processed_entry)

    # Write processed data to output file
    with open(output_file, "w") as f:
        for entry in processed_data:
            f.write(json.dumps(entry) + "\n")


def main():
    input_file = Path("dataset/train_hq_only.jsonl")
    output_file = Path("dataset/pie_dataset.jsonl")

    # Create output directory if it doesn't exist
    output_file.parent.mkdir(parents=True, exist_ok=True)

    # Process the data
    process_last_n_lines(input_file, output_file)


if __name__ == "__main__":
    main()
