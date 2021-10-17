import org.junit.jupiter.api.Test;

import java.util.HashMap;

import static org.junit.jupiter.api.Assertions.*;

class Task6Test4 {

    @Test
    void findLocalMin() {
        double[] array = {0.1, 5.0, 2.5, 6.2, 6.3, -0.2, 5.3, 0.0, 0.1, 0.005};

        HashMap<Integer, Double> expected = new HashMap<>() {{
            put(0, 0.1);
            put(2, 2.5);
            put(5, -0.2);
            put(7, 0.0);
            put(9, 0.005);
        }};
        HashMap<Integer, Double> actual = Task6.findLocalMin(array);

        assertEquals(expected, actual);
    }
}