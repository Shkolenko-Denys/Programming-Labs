package Task1;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class HyperbolaTest {

    @Test
    void getXbyY() {
        Hyperbola hyperbola = new Hyperbola(2.0, 3.0);
        double y = 4.0;
        double expected = 3.33;
        double actual = hyperbola.getXbyY(y);

        assertEquals(expected, actual);
    }

    @Test
    void getYbyX() {
        Hyperbola hyperbola = new Hyperbola(2.0, 3.5);
        double x = 3.33;
        double expected = 4.66;
        double actual = hyperbola.getYbyX(x);

        assertEquals(expected, actual);
    }
}