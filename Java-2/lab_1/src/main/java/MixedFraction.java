import org.jetbrains.annotations.NotNull;

/** Consists of a whole number and a proper fraction. */
public class MixedFraction extends Fraction implements IntegerNumber {

    @Number(name = "Whole", definition = "Integer part of a mixed fraction.")
    private int whole;

    public MixedFraction(int number) {
        super(0);
        whole = number;
    }

    public MixedFraction(int numerator, int denominator) {
        super(numerator, denominator);
    }

    public MixedFraction(int whole, int numerator, int denominator) {
        super(numerator, denominator);
        this.whole += whole;
    }

    public MixedFraction(@NotNull Fraction fraction) {
        super(fraction.getNumerator(), fraction.getDenominator());
    }

    @Arithmetic(name = "Mixed Fraction Simplifying", desc = "Make the mixed fraction as simple as possible")
    @Override
    public MixedFraction reduce() {
        super.reduce();
        int numerator = super.getNumerator();
        int denominator = super.getDenominator();

        if (Math.abs(numerator) >= denominator) {
            this.whole += numerator / denominator;
            if (whole != 0) {
                super.setNumerator(Math.abs(numerator) % denominator);
            }
            else {
                super.setNumerator(numerator % denominator);
            }
        }
        return this;
    }

    public int getWhole() {
        return whole;
    }

    public MixedFraction setWhole(int whole) {
        this.whole = whole;
        return this;
    }

    @Override
    public MixedFraction setNumerator(int numerator) {
        super.setNumerator(numerator);
        return this.reduce();
    }

    @Override
    public MixedFraction setDenominator(int denominator) {
        super.setDenominator(denominator);
        return this.reduce();
    }

    /** @return the fractional part */
    public Fraction getFraction() {
        return new Fraction(getNumerator(), getDenominator());
    }

    @Override
    public double getDouble() {
        if (whole < 0) {
            return whole - super.getDouble();
        }
        return whole + super.getDouble();
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof MixedFraction m)) {
            return false;
        }
        return whole == m.getWhole() && getNumerator() == m.getNumerator() && getDenominator() == m.getDenominator();
    }

    @Override
    public String toString() {
        if (whole != 0 && super.getNumerator() != 0) {
            return whole + "(" + super.toString() + ")";
        }
        if (whole != 0) {
            return whole + "";
        }
        return super.toString();
    }

    @Arithmetic(name = "Integer Addition", args = {"integer summand"}, desc = "Finding the sum")
    @Override
    public MixedFraction add(int number) {
        if (whole < 0) {
            super.neg();
        }
        super.add(number);
        return this;
    }

    @Arithmetic(name = "Fraction Addition", args = {"fraction summand"}, desc = "Finding the sum")
    @Override
    public MixedFraction add(@NotNull Fraction fraction) {
        if (whole < 0) {
            super.neg();
        }
        int tempWhole = whole;
        Fraction tempFraction = this.getFraction().add(fraction);
        this.reset();
        super.add(tempFraction);
        return this.add(tempWhole);
    }

    @Arithmetic(name = "Mixed Fraction Addition",
            args = {"mixed fraction summand"}, desc = "Finding the sum")
    public MixedFraction add(MixedFraction fraction) {
        return this.add(getImproper(fraction));
    }

    @Arithmetic(name = "Integer Subtraction",
            args = {"integer subtrahend"}, desc = "Finding the difference")
    @Override
    public MixedFraction sub(int number) {
        return this.add(-number);
    }

    @Arithmetic(name = "Fraction Subtraction",
            args = {"fraction subtrahend"}, desc = "Finding the difference")
    @Override
    public MixedFraction sub(@NotNull Fraction fraction) {
        return this.add(fraction.neg());
    }

    @Arithmetic(name = "Mixed Fraction Subtraction",
            args = {"mixed fraction subtrahend"}, desc = "Finding the difference")
    public MixedFraction sub(@NotNull MixedFraction fraction) {
        return this.add(fraction.neg());
    }

    @Arithmetic(name = "Integer Multiplication",
            args = {"integer multiplier"}, desc = "Finding the product")
    @Override
    public MixedFraction mul(int number) {
        if (whole < 0) {
            super.neg();
        }
        whole *= number;
        super.mul(number);
        return this;
    }

    @Arithmetic(name = "Fraction Multiplication",
            args = {"fraction multiplier"}, desc = "Finding the product")
    @Override
    public MixedFraction mul(@NotNull Fraction fraction) {
        fraction.mul(getImproper(this));
        return this.reset().add(fraction);
    }

    @Arithmetic(name = "Mixed Fraction Multiplication",
            args = {"mixed fraction multiplier"}, desc = "Finding the product")
    public MixedFraction mul(MixedFraction fraction) {
        return this.mul(getImproper(fraction));
    }

    @Arithmetic(name = "Integer Division",
            args = {"integer divisor"}, desc = "Finding the quotient")
    @Override
    public MixedFraction div(int number) {
        return this.mul(new Fraction(1, number));
    }

    @Arithmetic(name = "Fraction Division",
            args = {"fraction divisor"}, desc = "Finding the quotient")
    @Override
    public MixedFraction div(@NotNull Fraction fraction) {
        return this.mul(fraction.invert());
    }

    @Arithmetic(name = "Mixed Fraction Division",
            args = {"mixed fraction divisor"}, desc = "Finding the quotient")
    public MixedFraction div(MixedFraction fraction) {
        return this.mul(getImproper(fraction).invert());
    }

    @Arithmetic(name = "Mixed Fraction Negative", desc = "Finding the negative")
    @Override
    public MixedFraction neg() {
        whole = -whole;
        return this;
    }

    @Arithmetic(name = "Mixed Fraction Reset", desc = "Reset the mixed fraction")
    public MixedFraction reset() {
        whole = 0;
        setNumerator(0);
        setDenominator(1);
        return this;
    }

    /** Converting Mixed Fraction to Improper Fraction. */
    @Arithmetic(name = "Mixed Fraction Improper",
            args = {"mixed fraction"}, desc = "Finding the improper")
    public Fraction getImproper(@NotNull MixedFraction fraction) {
        if (fraction.whole < 0) {
            return new Fraction(
                -(-fraction.whole * fraction.getDenominator() + fraction.getNumerator()),
                fraction.getDenominator());
        }
        return new Fraction(
                fraction.whole * fraction.getDenominator() + fraction.getNumerator(),
                fraction.getDenominator());
    }
}
