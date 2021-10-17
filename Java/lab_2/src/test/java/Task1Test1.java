import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Task1Test1 {

    @Test
    void getFinalArray() {
        double[] originalArray = {};
        double[] expected = {};

        double[] actual = Task1.getFinalArray(originalArray);

        assertArrayEquals(expected, actual);
    }
}