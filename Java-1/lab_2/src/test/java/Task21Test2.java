import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Task21Test2 {

    @Test
    void linearCombination() {
        double[] array1 = {3.0, 3.4, 2.3, 9.0, -2.9};
        double[] array2 = {2.3, 2.9};

        Exception exception = assertThrows(IllegalArgumentException.class, () -> {
            Task21.linearCombination(array1, array2);
        });

        String expectedMessage = "Must be array2.length >= array1.length";
        String actualMessage = exception.getMessage();

        assertTrue(actualMessage.contains(expectedMessage));
    }
}