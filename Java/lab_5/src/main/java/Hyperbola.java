import java.util.Objects;

public class Hyperbola implements MathFunction {

    private double a;
    private double b;

    public Hyperbola(double a, double b) {
        this.a = a;
        this.b = b;
    }

    public double getA() {
        return a;
    }

    public void setA(double a) {
        if (Math.abs(a) < EPS) {
            throw new IllegalArgumentException("the 'a' cannot be zero");
        }
        this.a = a;
    }

    public double getB() {
        return b;
    }

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

    public double getXbyY(double y) {
        double result = a * Math.sqrt(1 + (y * y) / (b * b));
        return Math.round(result * 100.0) / 100.0;
    }

    public double getYbyX(double x) {
        double result = b * Math.sqrt((x * x) / (a * a) - 1);
        return Math.round(result * 100.0) / 100.0;
    }
}
