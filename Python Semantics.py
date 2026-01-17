x = 2147483647 # The meaning of 'x' is mapped to the mathematical object "Integer".

print(f"The current value is: {x}")

# Python ignores the 32-bit machine limit and finds a new memory to store the correct mathematical result.
x = x + 1

print(f"New Value (Mathematical): {x}") # Outputs: 2147483648
