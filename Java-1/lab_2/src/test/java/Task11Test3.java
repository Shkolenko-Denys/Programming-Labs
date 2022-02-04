import org.junit.jupiter.api.Test;

import java.util.HashMap;

import static org.junit.jupiter.api.Assertions.*;

class Task11Test3 {

    @Test
    void findOutOfRange() {
        double min = 5.0;
        double max = 15.0;
        double[] array = {0.0, 2.3, -23.2, 10.5, 14.99, 15.001, -4.9};

        HashMap<Integer, Double> expected = new HashMap<>() {{
            put(0, 0.0);
            put(1, 2.3);
            put(2, -23.2);
            put(5, 15.001);
            put(6, -4.9);
        }};
        HashMap<Integer, Double> actual = Task11.findOutOfRange(min, max, array);

        assertEquals(expected, actual);
    }
}