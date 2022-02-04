sign = ("+", "-")
result = True
prev_is_digit = False

user_input = input("Enter the formula: ")

for char in user_input:
    if char.isdigit():
        prev_is_digit = True
    elif (char in sign) and prev_is_digit:
        prev_is_digit = False
    else:
        result = False
        break
else:  # the last character must not be the sign
    if not prev_is_digit:
        result = False

print(result, eval(user_input) if result else None)
