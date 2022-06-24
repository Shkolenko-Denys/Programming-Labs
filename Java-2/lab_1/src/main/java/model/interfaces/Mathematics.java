package model.interfaces;

import model.classes.Fraction;

public interface Mathematics {

    Fraction add(int number);
    Fraction add(Fraction fraction);

    Fraction sub(int number);
    Fraction sub(Fraction fraction);

    Fraction mul(int number);
    Fraction mul(Fraction fraction);

    Fraction div(int number);
    Fraction div(Fraction fraction);

    Fraction neg();
    Fraction invert();
}
