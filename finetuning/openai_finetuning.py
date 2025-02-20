import time
from openai import OpenAI


def upload_training_file(client: OpenAI, file_path: str) -> str:
    """Upload a training file and return the file ID."""
    file_response = client.files.create(
        file=open(file_path, "rb"),
        purpose="fine-tune",
    )
    print(f"Uploaded file {file_path} - File ID: {file_response.id}")
    return file_response.id


def create_fine_tuning_job(client: OpenAI, file_id: str, model: str) -> str:
    """Create a fine-tuning job and return the job ID."""
    job = client.fine_tuning.jobs.create(
        training_file=file_id,
        model=model,
    )
    print(f"Created fine-tuning job - Job ID: {job.id}")
    return job


def monitor_fine_tuning_job(
    client: OpenAI, job_id: str, polling_interval: int = 5
):
    """Monitor the status of a fine-tuning job until completion."""
    while True:
        job = client.fine_tuning.jobs.retrieve(job_id)
        print(f"Job status: {job.status}")
        if job.status == "succeeded":
            break
        time.sleep(polling_interval)


def run_fine_tuning(training_file: str, model: str = "gpt-4o-mini-2024-07-18"):
    """Run the complete fine-tuning pipeline for a single file."""
    client = OpenAI()

    # Upload file
    file_id = upload_training_file(client, training_file)

    # Create and monitor fine-tuning job
    job = create_fine_tuning_job(client, file_id, model)
    monitor_fine_tuning_job(client, job.id)


if __name__ == "__main__":
    # Example usage for multiple training files
    training_files = ["dataset/pie_dataset.jsonl"]

    for training_file in training_files:
        print(f"\nStarting fine-tuning for {training_file}")
        run_fine_tuning(training_file)
