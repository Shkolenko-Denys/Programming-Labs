package Task40;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FractionNumberTest {

    @Test
    void add() {
        FractionNumber fraction = new FractionNumber(2, 2, 5);
        fraction.add(2);

        int expected = 4;
        int actual = fraction.getWhole();

        assertEquals(expected, actual);
    }

    @Test
    void sub() {
        FractionNumber fraction = new FractionNumber(2, 2, 5);
        fraction.sub(2);

        int expected = 0;
        int actual = fraction.getWhole();

        assertEquals(expected, actual);
    }

    @Test
    void mult() {
        FractionNumber fraction = new FractionNumber(2, 2, 5);
        fraction.mult(3);

        int expected = 6;
        int actual = fraction.getWhole();

        assertEquals(expected, actual);
    }

    @Test
    void div() {
        FractionNumber fraction = new FractionNumber(2, 2, 5);
        fraction.div(2);

        int expected = 1;
        int actual = fraction.getWhole();

        assertEquals(expected, actual);
    }

    @Test
    void get_float() {
        FractionNumber fraction = new FractionNumber(2, 2, 5);

        double expected = 2.4;
        double actual = fraction.get_float();

        assertEquals(expected, actual);
    }
}