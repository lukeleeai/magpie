


# import difflib

# # Example files (replace with your actual file reads)
# with open("logs/codes/0.5521526_27.txt", "r") as f:
#     code1 = f.read()

# with open("logs/codes/0.5521526_27_change.txt", "r") as f:
#     code2 = f.read()

# def get_changes_only_diff(code1, code2):
#     # Split the code into lines
#     s1 = code1.splitlines(keepends=False)
#     s2 = code2.splitlines(keepends=False)
    
#     # Use Differ to compare lines
#     differ = difflib.Differ()
#     diff = list(differ.compare(s1, s2))
    
#     # Collect only changes
#     output = []
#     line_num1 = 0  # Original file line number
#     line_num2 = 0  # New file line number
    
#     for line in diff:
#         if line.startswith('- '):
#             line_num1 += 1
#             output.append(f"Line {line_num1} (removed): {line[2:]}")
#         elif line.startswith('+ '):
#             line_num2 += 1
#             output.append(f"Line {line_num2} (added): {line[2:]}")
#         elif line.startswith('  '):
#             line_num1 += 1
#             line_num2 += 1
#             # Explicitly skip unchanged lines
#         # Ignore '? ' lines for simplicity unless you want character-level hints
    
#     return "\n".join(output) if output else "No changes detected."

# # Test with example usage
# if __name__ == "__main__":
#     print("=== Changes Only Diff ===")
#     changes_diff = get_changes_only_diff(code1, code2)
#     print(changes_diff)

#     # For debugging, let’s test with a simple example
#     test_code1 = "line1\nline2\nline3"
#     test_code2 = "line1\nnew_line\nline3"
#     print("\n=== Test Case ===")
#     test_diff = get_changes_only_diff(test_code1, test_code2)
#     print(test_diff)