package Task1;

import java.util.Objects;

/**
 * Class that describes hyperbola in math
 *
 * @author Shkolenko
 * @version 1.0
 */
public class Hyperbola implements MathFunction {

    /** Parameter 'a' in formula */
    private double a;

    /** Parameter 'b' in formula */
    private double b;

    /**
     * Create new object
     *
     * @param a parameter 'a' in formula
     * @param b parameter 'b' in formula
     */
    public Hyperbola(double a, double b) {
        setA(a);
        setB(b);
    }

    /**
     * @return parameter 'a'
     */
    public double getA() {
        return a;
    }

    /**
     * @param a parameter 'a' in formula
     */
    public void setA(double a) {
        if (Math.abs(a) < EPS) {
            throw new IllegalArgumentException("the 'a' cannot be zero");
        }
        this.a = a;
    }

    /**
     * @return parameter 'b'
     */
    public double getB() {
        return b;
    }

    /**
     * @param b parameter 'a' in formula
     */
    public void setB(double b) {
        if (Math.abs(b) < EPS) {
            throw new IllegalArgumentException("the 'b' cannot be zero");
        }
        this.b = b;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Hyperbola hyperbola = (Hyperbola) o;
        return Double.compare(hyperbola.a, a) == 0
                && Double.compare(hyperbola.b, b) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(a, b);
    }

    @Override
    public String toString() {
        return "(x^2 / " + a + "^2) - (y^2 / " + b + "^2) = 1";
    }

    /**
     * @param y argument 'y'
     * @return argument 'x'
     */
    public double getXbyY(double y) {
        double result = a * Math.sqrt(1 + (y * y) / (b * b));
        return Math.round(result * 100.0) / 100.0;
    }

    /**
     * @param x argument 'x'
     * @return argument 'y'
     */
    public double getYbyX(double x) {
        double result = b * Math.sqrt((x * x) / (a * a) - 1);
        return Math.round(result * 100.0) / 100.0;
    }
}
