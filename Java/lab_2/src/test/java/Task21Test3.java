import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Task21Test3 {

    @Test
    void linearCombination() {
        double[] array1 = {12.0, 14.0, 16.0, 18.0, 20.0};
        double[] array2 = {1.0, 2.0, 3.0, 4.0, 5.0};

        boolean actual = Task21.linearCombination(array1, array2);

        assertTrue(actual);
    }
}