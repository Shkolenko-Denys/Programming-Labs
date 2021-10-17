import org.junit.jupiter.api.Test;

import java.util.HashMap;

import static org.junit.jupiter.api.Assertions.*;

class Task6Test2 {

    @Test
    void findLocalMin() {
        double[] array = {2.5};

        HashMap<Integer, Double> expected = new HashMap<>() {{
            put(0, 2.5);
        }};
        HashMap<Integer, Double> actual = Task6.findLocalMin(array);

        assertEquals(expected, actual);
    }
}