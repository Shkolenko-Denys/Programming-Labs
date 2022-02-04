import argparse

parser = argparse.ArgumentParser()
parser.add_argument("x", type=int, help="first int operand")
parser.add_argument("op", choices=["+", "-", "*", "/"], help="operator")
parser.add_argument("y", type=int, help="second int operand")
parser.add_argument("-v", "--verbose", action="store_true",
                    help="increase output verbosity")
args = parser.parse_args()

expression = str(args.x) + args.op + str(args.y)
try:
    result = eval(expression)
except ZeroDivisionError:
    result = None

if args.verbose:
    print(expression, "==", result)
else:
    print(result)
