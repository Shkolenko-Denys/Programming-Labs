package Task40;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FractionTest {

    @Test
    void add() {
        Fraction fraction = new Fraction(1, 2);
        fraction.add(2);

        int expected = 5;
        int actual = fraction.getNumerator();

        assertEquals(expected, actual);
    }

    @Test
    void sub() {
        Fraction fraction = new Fraction(1, 2);
        fraction.sub(2);

        int expected = -3;
        int actual = fraction.getNumerator();

        assertEquals(expected, actual);
    }

    @Test
    void mult() {
        Fraction fraction = new Fraction(1, 2);
        fraction.mult(3);

        int expected = 3;
        int actual = fraction.getNumerator();

        assertEquals(expected, actual);
    }

    @Test
    void div() {
        Fraction fraction = new Fraction(1, 2);
        fraction.div(2);

        int expected = 4;
        int actual = fraction.getDenominator();

        assertEquals(expected, actual);
    }

    @Test
    void get_float() {
        Fraction fraction = new Fraction(1, 3);

        double expected = 0.33;
        double actual = fraction.get_float();

        assertEquals(expected, actual);
    }
}