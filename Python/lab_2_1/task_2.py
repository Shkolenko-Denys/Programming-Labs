import sys
from math import gcd


class Rational:
    """Class that represents a rational number.

    The class contains methods for displaying a rational number in
    fractional or floating-point format.
    """

    def __init__(self, numerator=1, denominator=1):
        """Sets the fraction in reduced form.

        Args:
            numerator (int): The numerator of the rational number
                (defaults to 1.0).
            denominator (int): The denominator of the rational number
                (defaults to 1.0).

        Raises:
            ZeroDivisionError: If the denominator is zero.
            TypeError: If numerator or denominator is not an integer.
        """
        if not denominator:
            raise ZeroDivisionError("the denominator is zero")
        if not isinstance(numerator, int):
            raise TypeError("the numerator must be an integer")
        if not isinstance(denominator, int):
            raise TypeError("the denominator must be an integer")

        divisor = gcd(numerator, denominator)
        self.__numerator = numerator // divisor
        self.__denominator = denominator // divisor

    def display_fraction(self):
        """Display the rational number in fractional format."""
        print(self.__numerator, '/', self.__denominator)

    def display_float(self):
        """Display the rational number in floating-point format."""
        print(self.__numerator / self.__denominator)


if __name__ == "__main__":
    try:
        obj = Rational(2, 4)
    except (ZeroDivisionError, TypeError) as e:
        print("Error:", e)
        sys.exit(1)

    obj.display_fraction()
    obj.display_float()
