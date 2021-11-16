package Task40;

import java.util.Objects;

/**
 * Class that describes fraction with arithmetic operations
 *
 * @author Shkolenko
 * @version 1.0
 */
public class Fraction implements Arithmetic {

    /** the numerator of the fraction */
    private int numerator;

    /** the denominator of the fraction */
    private int denominator;

    /**
     * @param numerator numerator of the fraction
     * @param denominator denominator of the fraction
     */
    public Fraction(int numerator, int denominator) {
        setNumerator(numerator);
        setDenominator(denominator);
    }

    public int getNumerator() {
        return numerator;
    }

    public void setNumerator(int numerator) {
        this.numerator = numerator;
    }

    public int getDenominator() {
        return denominator;
    }

    public void setDenominator(int denominator) {
        if (denominator == 0) {
            throw new IllegalArgumentException("division by zero");
        }
        this.denominator = denominator;
    }

    /**
     * @param number number for addition
     */
    public void add(int number) {
        numerator += number * denominator;
    }

    /**
     * @param number number for subtraction
     */
    public void sub(int number) {
        numerator -= number * denominator;
    }

    /**
     * @param number number for multiplication
     */
    public void mult(int number) {
        numerator *= number;
    }

    /**
     * @param number number for division
     */
    public void div(int number) {
        if (number == 0) {
            throw new IllegalArgumentException("division by zero");
        }
        denominator *= number;
    }

    /**
     * @return float-format of the fraction
     */
    public double get_float() {
        return Math.round((double) numerator / denominator * 100.0) / 100.0;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Fraction fraction = (Fraction) o;
        return numerator == fraction.numerator
                && denominator == fraction.denominator;
    }

    @Override
    public int hashCode() {
        return Objects.hash(numerator, denominator);
    }

    @Override
    public String toString() {
        return numerator + " / " + denominator;
    }
}
