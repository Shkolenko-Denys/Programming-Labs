import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Task21Test1 {

    @Test
    void linearCombination() {
        double[] array1 = {3.0};
        double[] array2 = {2.3, 2.9};

        Exception exception = assertThrows(IllegalArgumentException.class, () -> {
            Task21.linearCombination(array1, array2);
        });

        String expectedMessage = "Array length must be 2 or greater";
        String actualMessage = exception.getMessage();

        assertTrue(actualMessage.contains(expectedMessage));
    }
}