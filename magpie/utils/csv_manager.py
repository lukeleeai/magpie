import pandas as pd
import os


class CSVManager:
    def __init__(self, file_path: str, index_col: str, columns: list):
        self.df = pd.DataFrame(columns=columns)
        self.df.set_index(index_col, inplace=True)

        self.file_path = file_path
        os.makedirs(os.path.dirname(file_path), exist_ok=True)

        # Load existing data if file exists
        if os.path.exists(self.file_path):
            try:
                # First try to read with specified index, ensuring it's a string
                self.df = pd.read_csv(
                    self.file_path, index_col=index_col, dtype={index_col: str}
                )
            except (ValueError, KeyError):
                # If that fails, try reading the first column as index
                self.df = pd.read_csv(
                    self.file_path, index_col=0, dtype={0: str}
                )
                # Rename the index for consistency
                self.df.index.name = index_col

            # Ensure the index is treated as a string
            self.df.index = self.df.index.astype(str)

    def add_entry(self, index_value: str, data: dict):
        """
        Add a new entry in the DataFrame. If the index_value already exists, a new row will be added with an incremented experiment_id.

        Args:
            index_value: Unique identifier for the entry
            data: Dictionary containing column data
        """
        index_value = str(
            index_value
        )  # Ensure the index_value is treated as a string

        # Determine the current experiment_id
        existing_rows = self.df[self.df.index == index_value]
        exp_id = len(existing_rows)  # K rows with the same id

        # Add experiment_id to the data
        data["experiment_id"] = [exp_id]

        new_row = pd.DataFrame(data, index=[index_value])

        # Add new row regardless of existing index_value
        self.df = pd.concat([self.df, new_row])

        # Save after each update
        self.save()

    def save(self):
        """
        Save the DataFrame to a CSV file.
        """
        # Ensure index is saved with the correct name and as a string
        # self.df.index = self.df.index.astype(str)
        # print("Index: ", self.df.index)
        self.df.reset_index().to_csv(self.file_path, index=False)

    def get_data(self) -> pd.DataFrame:
        """
        Returns the DataFrame containing all data.
        """
        return self.df.copy()


class ResultsManager(CSVManager):
    def __init__(self, logs_dir: str = "logs", filename: str = "llm_eoc"):
        file_path = os.path.join(logs_dir, filename + ".csv")
        columns = [
            "id",
            "llm_prob",
            "reference_time",
            "new_code_time",
            "new_code",
        ]
        super().__init__(file_path, "id", columns)

    def add_result(
        self,
        id: str,
        llm_prob: float,
        new_code: str,
        new_code_time: float,
        reference_time: float,
    ):
        data = {
            "llm_prob": [llm_prob],
            "reference_time": [reference_time],
            "new_code_time": [new_code_time],
            "new_code": [new_code],
        }
        self.add_entry(id, data)


class PromptsDataset(CSVManager):
    def __init__(self, dataset_dir: str = "logs"):
        file_path = os.path.join(dataset_dir, "prompts_dataset.csv")
        columns = [
            "unique_id",
            "problem_id",
            "parent_name",
            "prompt",
        ]
        super().__init__(file_path, "unique_id", columns)

    def add_prompt(self, problem_id: str, parent_name: str, prompt: str):
        unique_id = f"{problem_id}_{parent_name}"
        data = {
            "problem_id": [problem_id],
            "parent_name": [parent_name],
            "prompt": [prompt],
        }
        self.add_entry(unique_id, data)
