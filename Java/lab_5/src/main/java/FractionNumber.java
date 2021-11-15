import java.util.Objects;

public class FractionNumber extends Fraction {

    private int whole;

    public FractionNumber(int whole, int numerator, int denominator) {
        super(numerator, denominator);
        this.whole = whole;
    }

    public int getWhole() {
        return whole;
    }

    public void setWhole(int whole) {
        this.whole = whole;
    }

    public void add(double number) {
        whole += number;
    }

    public void sub(double number) {
        whole -= number;
    }

    public void mult(double number) {
        whole *= number;
    }

    public void div(double number) {
        whole /= number;
    }

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
