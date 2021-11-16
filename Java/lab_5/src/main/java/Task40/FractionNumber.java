package Task40;

import java.util.Objects;

/**
 * Class that describes fraction with whole part
 *
 * @author Shkolenko
 * @version 1.0
 */
public class FractionNumber extends Fraction {

    private int whole;

    public FractionNumber(int whole, int numerator, int denominator) {
        super(numerator, denominator);
        setWhole(whole);
    }

    public int getWhole() {
        return whole;
    }

    public void setWhole(int whole) {
        this.whole = whole;
    }

    /**
     * @param number number for addition
     */
    public void add(int number) {
        whole += number;
    }

    /**
     * @param number number for subtraction
     */
    public void sub(int number) {
        whole -= number;
    }

    /**
     * @param number number for multiplication
     */
    public void mult(int number) {
        whole *= number;
    }

    /**
     * @param number number for division
     */
    public void div(int number) {
        if (number == 0) {
            throw new IllegalArgumentException("division by zero");
        }
        whole /= number;
    }

    /**
     * @return float-format of the fraction
     */
    public double get_float() {
        return whole + super.get_float();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        FractionNumber that = (FractionNumber) o;
        return whole == that.whole;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), whole);
    }

    @Override
    public String toString() {
        return whole + " + " + super.toString();
    }
}
