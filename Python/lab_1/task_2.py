import argparse
import operator

parser = argparse.ArgumentParser()
parser.add_argument("func", help="standard math function")
parser.add_argument("x", type=int, help="first int operand")
parser.add_argument("y", type=int, help="second int operand")
parser.add_argument("-v", "--verbose", action="store_true",
                    help="increase output verbosity")
args = parser.parse_args()

caller = operator.methodcaller(args.func, args.x, args.y)
try:
    result = caller(operator)
except ZeroDivisionError:
    result = None

if args.verbose:
    print("{}({}, {}) == {}".format(args.func, args.x, args.y, result))
else:
    print(result)
