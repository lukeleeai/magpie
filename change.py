import re

target_code = """
print(1)
print(2)
    print(3)
    print(4)
    print(5)
    print(6)
print(7)
print(8)
print(9)
print(10)
"""

code_change = """
- print(4)
- print(5)
+   print(100)
+   print(101)
- print(9)
+ print(102)
+ print(103)
"""

# Parse the target code into lines
target_lines = target_code.strip().split('\n')

# Group changes
changes = []
current_removals = []
current_additions = []

# Process each line in the code_change
for line in code_change.strip().split('\n'):
    if not line:
        continue
        
    # Use simple startswith for detecting markers
    if line.startswith('-'):
        # If we have collected removals and additions, and now see a new removal,
        # store the previous change group and start a new one
        if current_removals and current_additions:
            changes.append((current_removals.copy(), current_additions.copy()))
            current_additions = []
            current_removals = []
        
        # Extract the content after the '-' but strip it for comparison
        content = line[1:].strip()
        current_removals.append(content)
    
    elif line.startswith('+'):
        # Extract the content after the '+' but preserve the whitespace
        content = line[1:]  # Keep the original spacing
        current_additions.append(content)

# Add the last change group if it exists
if current_removals or current_additions:
    changes.append((current_removals.copy(), current_additions.copy()))

# Apply the changes to the target code
result_lines = []
i = 0

while i < len(target_lines):
    matched = False
    
    for removals, additions in changes:
        # Check if we have enough lines left to match
        if i + len(removals) <= len(target_lines):
            # Use regex to match each line, ignoring whitespace differences
            match = True
            for j, removal in enumerate(removals):
                # Create a pattern that matches the line content, ignoring whitespace
                pattern = r'^\s*' + re.escape(removal) + r'\s*$'
                if not re.match(pattern, target_lines[i + j]):
                    match = False
                    break
            
            if match:
                # Add the replacement lines with their original spacing
                result_lines.extend(additions)
                # Skip the removed lines
                i += len(removals)
                matched = True
                break
    
    if not matched:
        result_lines.append(target_lines[i])
        i += 1

# Output the result
print("Original code:")
print(target_code)
print("\nChanges:")
print(code_change)
print("\nResult:")
print('\n'.join(result_lines))
