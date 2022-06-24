package model.classes;

import model.interfaces.Arithmetic;
import model.interfaces.Mathematics;
import model.interfaces.Number;
import model.interfaces.Rational;
import org.apache.commons.math3.util.Precision;
import org.jetbrains.annotations.NotNull;

/**
 * The fraction class implements a rational number, where
 * the numerator is an integer and the denominator is a natural number.
 */
public class Fraction implements Mathematics, Rational {

    @Number(name = "Numerator", definition = "The top number in a fraction.")
    private int numerator;

    @Number(name = "Denominator", definition = "The bottom number in a fraction.")
    private int denominator = 1;

    public Fraction(int numerator) {
        this.numerator = numerator;
    }

    public Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw new IllegalArgumentException("the denominator is zero");
        }
        if (denominator < 0) {
            this.numerator = -numerator;
            this.denominator = -denominator;
        }
        else {
            this.numerator = numerator;
            this.denominator = denominator;
        }
        this.reduce();
    }

    /** Reducing fractions means simplifying a fraction. */
    @Arithmetic(name = "model.classes.Fraction Simplifying", desc = "Make the fraction as simple as possible")
    public Fraction reduce() {
        int gcd = gcd(Math.abs(numerator), denominator);
        // if the numerator is negative, abs is used because
        // the numerator must remain negative
        numerator /= gcd;
        denominator /= gcd;
        return this;
    }

    /** Euclid's algorithm to find the GCD. */
    public static int gcd(int n1, int n2) {
        if (n2 == 0) {
            return n1;
        }
        return gcd(n2, n1 % n2);
    }

    public int getNumerator() {
        return numerator;
    }

    public int getDenominator() {
        return denominator;
    }

    public Fraction setNumerator(int numerator) {
        this.numerator = numerator;
        return this.reduce();
    }

    public Fraction setDenominator(int denominator) {
        if (denominator == 0) {
            throw new IllegalArgumentException("the denominator is zero");
        }
        if (denominator < 0) {
            this.numerator = -this.numerator;
            this.denominator = -denominator;
        }
        else {
            this.denominator = denominator;
        }
        return this.reduce();
    }

    /** @return the fraction in floating-point format */
    public double getDouble() {
        return Precision.round((double) numerator / denominator, 2);
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Fraction f)) {
            return false;
        }
        return numerator == f.numerator && denominator == f.denominator;
    }

    @Override
    public String toString() {
        if (denominator != 1) {
            return numerator + "/" + denominator;
        }
        else {
            return numerator + "";
        }
    }

    @Arithmetic(name = "Integer Addition", args = {"integer summand"}, desc = "Finding the sum")
    public Fraction add(int number) {
        numerator += number * denominator;
        return this.reduce();
    }

    @Arithmetic(name = "model.classes.Fraction Addition", args = {"fraction summand"}, desc = "Finding the sum")
    public Fraction add(@NotNull Fraction fraction) {
        numerator *= fraction.denominator;
        numerator += fraction.numerator * denominator;
        denominator *= fraction.denominator;
        return this.reduce();
    }

    @Arithmetic(name = "Integer Subtraction", args = {"integer subtrahend"}, desc = "Finding the difference")
    public Fraction sub(int number) {
        return this.add(-number);
    }

    @Arithmetic(name = "model.classes.Fraction Subtraction", args = {"fraction subtrahend"}, desc = "Finding the difference")
    public Fraction sub(@NotNull Fraction fraction) {
        fraction.neg();
        return this.add(fraction);
    }

    @Arithmetic(name = "Integer Multiplication", args = {"integer multiplier"}, desc = "Finding the product")
    public Fraction mul(int number) {
        numerator *= number;
        return this.reduce();
    }

    @Arithmetic(name = "model.classes.Fraction Multiplication", args = {"fraction multiplier"}, desc = "Finding the product")
    public Fraction mul(@NotNull Fraction fraction) {
        numerator *= fraction.numerator;
        denominator *= fraction.denominator;
        return this.reduce();
    }

    @Arithmetic(name = "Integer Division", args = {"integer divisor"}, desc = "Finding the quotient")
    public Fraction div(int number) {
        return this.mul(new Fraction(1, number));
    }

    @Arithmetic(name = "model.classes.Fraction Division", args = {"fraction divisor"}, desc = "Finding the quotient")
    public Fraction div(@NotNull Fraction fraction) {
        fraction.invert();
        return this.mul(fraction);
    }

    @Arithmetic(name = "model.classes.Fraction Negative", desc = "Finding the negative")
    public Fraction neg() {
        numerator = -numerator;
        return this;
    }

    /** Swapping the numerator and denominator. */
    @Arithmetic(name = "model.classes.Fraction Inverse", desc = "Finding the inverse of a fraction")
    public Fraction invert() {
        if (numerator == 0) {
            throw new ArithmeticException("division by zero");
        }
        int temp = numerator;
        if (temp < 0) {
            numerator = -denominator;
        } else {
            numerator = denominator;
        }
        denominator = Math.abs(temp);
        return this;
    }
}
