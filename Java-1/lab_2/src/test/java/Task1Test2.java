import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Task1Test2 {

    @Test
    void getFinalArray() {
        double[] originalArray = {1.0, 2.0, 3.0, 0.0, -3.4, -17.0, 0.0, 1.0E26, 0.0, -45.0};
        double[] expected = {-3.4, -17.0, -45.0, 0.0, 0.0, 0.0, 1.0, 2.0, 3.0, 1.0E26};

        double[] actual = Task1.getFinalArray(originalArray);

        assertArrayEquals(expected, actual);
    }
}