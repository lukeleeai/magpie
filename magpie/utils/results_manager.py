import pandas as pd
import os


class ResultsManager:
    def __init__(self, logs_dir: str = "logs"):
        self.df = pd.DataFrame(
            columns=[
                "id",
                "llm_prob",
                "reference_time",
                "new_code_time",
                "new_code",
            ]
        )
        self.df.set_index("id", inplace=True)

        self.logs_dir = logs_dir
        os.makedirs(logs_dir, exist_ok=True)
        self.file_path = os.path.join(logs_dir, "results.csv")

        # Load existing results if file exists
        if os.path.exists(self.file_path):
            try:
                # First try to read with id as index, ensuring it's a string
                self.df = pd.read_csv(
                    self.file_path, index_col="id", dtype={"id": str}
                )
            except (ValueError, KeyError):
                # If that fails, try reading the first column as index
                self.df = pd.read_csv(
                    self.file_path, index_col=0, dtype={0: str}
                )
                # Rename the index to 'id' for consistency
                self.df.index.name = "id"

            # Ensure the index is treated as a string
            self.df.index = self.df.index.astype(str)

    def add_result(
        self,
        id: str,
        llm_prob: float,
        new_code: str,
        new_code_time: float,
        reference_time: float,
    ):
        """
        Add or update a result in the DataFrame. If the ID already exists, the row will be overwritten.

        Args:
            id: Unique identifier for the result
            model_code: The model code
            model_code_time: Time taken by the model code
            reference_time: Reference time for comparison
        """
        id = str(id)  # Ensure the ID is treated as a string

        new_row = pd.DataFrame(
            {
                "new_code": [new_code],
                "new_code_time": [new_code_time],
                "reference_time": [reference_time],
                "llm_prob": [llm_prob],
            },
            index=[id],
        )

        self.df.update(new_row)  # Update existing row if ID exists
        if id not in self.df.index:  # Add new row if ID doesn't exist
            self.df = pd.concat([self.df, new_row])

        # Save after each update
        self.save_results()

    def save_results(self):
        """
        Save the results DataFrame to a CSV file in the logs directory.
        """
        # Ensure index is saved with name 'id' and as a string
        self.df.index = self.df.index.astype(str)
        self.df.index.name = "id"
        self.df.to_csv(self.file_path)

    def get_results(self) -> pd.DataFrame:
        """
        Returns the DataFrame containing all results.
        """
        return self.df.copy()
