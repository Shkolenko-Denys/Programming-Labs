import java.util.Objects;

public class Fraction implements Arithmetic {

    private int numerator;
    private int denominator;

    public Fraction(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
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

    public void add(double number) {
        numerator += number * denominator;
    }

    public void sub(double number) {
        numerator -= number * denominator;
    }

    public void mult(double number) {
        numerator *= number;
    }

    public void div(double number) {
        denominator *= number;
    }

    public double get_float() {
        return Math.round((double) numerator / denominator * 100.0) / 100.0;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Fraction fraction = (Fraction) o;
        return numerator == fraction.numerator && denominator == fraction.denominator;
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
