package injection.model.classes;

public class Memento {

    private final int whole;
    private final int numerator;
    private final int denominator;

    public Memento(int whole, int numerator, int denominator) {
        this.whole = whole;
        this.numerator = numerator;
        this.denominator = denominator;
    }

    public int getWhole() {
        return whole;
    }

    public int getNumerator() {
        return numerator;
    }

    public int getDenominator() {
        return denominator;
    }
}
