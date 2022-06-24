package model.interfaces;

import model.classes.Fraction;

public interface Rational {

    Fraction reduce();

    int getNumerator();
    int getDenominator();

    Fraction setNumerator(int numerator);
    Fraction setDenominator(int denominator);

    double getDouble();
}
