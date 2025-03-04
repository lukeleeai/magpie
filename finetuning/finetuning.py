import time
from openai import OpenAI

client = OpenAI()

# job = client.fine_tuning.jobs.create(
#     training_file="logs/train.jsonl",
#     model="gpt-4o-mini-2024-07-18",
# )

# Upload the dataset and get the file id
file_id = client.files.create(
    file=open("logs/train.jsonl", "rb"),
    purpose="fine-tune",
)
print("FILE ID: ", file_id)

# Create a fine-tuning job
job = client.fine_tuning.jobs.create(
    training_file=file_id.id,
    model="gpt-4o-mini-2024-07-18",
)
print("JOB ID: ", job.id)

# Check the status of the fine-tuning job every 5 seconds
while True:
    job = client.fine_tuning.jobs.retrieve(job.id)
    print(f"Job status: {job.status}")
    if job.status == "succeeded":
        break
    time.sleep(5)
