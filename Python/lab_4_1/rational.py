from math import gcd


class Rational:
    """Class that represents a rational number.

    The class contains methods for getting a rational number in
    fractional or floating-point format, for basic arithmetic
    operations, for comparison two Rational numbers or Rational-Integer.
    """

    def __init__(self, numerator=1, denominator=1):
        if not isinstance(numerator, int):
            raise TypeError("the numerator must be an integer")
        if not isinstance(denominator, int):
            raise TypeError("the denominator must be an integer")
        if not denominator:
            raise ZeroDivisionError("the denominator is zero")

        self.__numerator = numerator
        self.__denominator = denominator
        self.reduce()

    def __str__(self):
        return f"{self.numerator}/{self.denominator}"

    @property
    def numerator(self):
        return self.__numerator

    @numerator.setter
    def numerator(self, numerator):
        if not isinstance(numerator, int):
            raise TypeError("the numerator must be an integer")
        self.__numerator = numerator

    @property
    def denominator(self):
        return self.__denominator

    @denominator.setter
    def denominator(self, denominator):
        if not isinstance(denominator, int):
            raise TypeError("the denominator must be an integer")
        if not denominator:
            raise ZeroDivisionError("the denominator is zero")
        self.__denominator = denominator

    def reduce(self):
        divisor = gcd(self.numerator, self.denominator)
        self.__numerator = self.numerator // divisor
        self.__denominator = self.denominator // divisor

        if self.denominator < 0:
            self.__denominator *= -1
            self.__numerator *= -1

    def get_float(self):
        """Return Rational number in floating-point format."""
        return self.numerator / self.denominator

    def __neg__(self):
        return Rational(-self.numerator, self.denominator)

    def __add__(self, other):
        if isinstance(other, Rational):
            denominator = self.denominator * other.denominator
            numerator = self.numerator * other.denominator + \
                other.numerator * self.denominator
            return Rational(numerator, denominator)
        if isinstance(other, int):
            numerator = other * self.denominator + self.numerator
            return Rational(numerator, self.denominator)
        return NotImplemented

    def __sub__(self, other):
        if isinstance(other, Rational):
            denominator = self.denominator * other.denominator
            numerator = self.numerator * other.denominator - \
                other.numerator * self.denominator
            return Rational(numerator, denominator)
        if isinstance(other, int):
            numerator = self.numerator - other * self.denominator
            return Rational(numerator, self.denominator)
        return NotImplemented

    def __mul__(self, other):
        if isinstance(other, Rational):
            return Rational(self.numerator * other.numerator,
                            self.denominator * other.denominator)
        if isinstance(other, int):
            return Rational(self.numerator * other, self.denominator)
        return NotImplemented

    def __truediv__(self, other):
        if isinstance(other, Rational):
            return Rational(self.numerator * other.denominator,
                            self.denominator * other.numerator)
        if isinstance(other, int):
            return Rational(self.numerator, self.denominator * other)
        return NotImplemented

    def __radd__(self, other):
        if isinstance(other, int):
            return self.__add__(other)
        return NotImplemented

    def __rsub__(self, other):
        if isinstance(other, int):
            return -self.__sub__(other)
        return NotImplemented

    def __rmul__(self, other):
        if isinstance(other, int):
            return self.__mul__(other)
        return NotImplemented

    def __rtruediv__(self, other):
        if isinstance(other, int):
            return Rational(self.denominator * other, self.numerator)
        return NotImplemented

    def __iadd__(self, other):
        if isinstance(other, Rational):
            self.numerator = self.numerator * other.denominator + \
                other.numerator * self.denominator
            self.denominator *= other.denominator
        elif isinstance(other, int):
            self.numerator += other * self.denominator
        self.reduce()
        return self

    def __isub__(self, other):
        if isinstance(other, Rational):
            self.numerator = self.numerator * other.denominator - \
                other.numerator * self.denominator
            self.denominator *= other.denominator
        elif isinstance(other, int):
            self.numerator -= other * self.denominator
        self.reduce()
        return self

    def __imul__(self, other):
        if isinstance(other, Rational):
            self.numerator *= other.numerator
            self.denominator *= other.denominator
        if isinstance(other, int):
            self.numerator *= other
        self.reduce()
        return self

    def __itruediv__(self, other):
        if isinstance(other, Rational):
            self.numerator *= other.denominator
            self.denominator *= other.numerator
        if isinstance(other, int):
            self.denominator *= other
        self.reduce()
        return self

    def __lt__(self, other):
        if isinstance(other, Rational):
            return self.numerator * other.denominator < \
                   other.numerator * self.denominator
        if isinstance(other, int):
            return self.numerator < other * self.denominator
        return NotImplemented

    def __gt__(self, other):
        if isinstance(other, Rational):
            return self.numerator * other.denominator > \
                   other.numerator * self.denominator
        if isinstance(other, int):
            return self.numerator > other * self.denominator
        return NotImplemented

    def __eq__(self, other):
        if isinstance(other, Rational):
            return (self.numerator, self.denominator) == \
                   (other.numerator, other.denominator)
        if isinstance(other, int):
            return self.numerator == other * self.denominator
        return NotImplemented

    def __le__(self, other):
        return not self.__gt__(other)

    def __ge__(self, other):
        return not self.__lt__(other)

    def __ne__(self, other):
        return not self.__eq__(other)
