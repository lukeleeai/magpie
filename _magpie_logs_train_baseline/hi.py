import os

def count_words_in_directory(directory):
    files = os.listdir(directory)
    num_dff = 0
    for file in files:
        if file.endswith('.diff'):
            num_dff += 1

    return num_dff

def main():
    current_directory = os.getcwd()
    num_dff = count_words_in_directory(current_directory)

    print(f"Count of 'diff': {num_dff}")

if __name__ == "__main__":
    main()
