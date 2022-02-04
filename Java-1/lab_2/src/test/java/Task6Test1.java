import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Task6Test1 {

    @Test
    void findLocalMin() {
        double[] array = {};

        Exception exception = assertThrows(IllegalArgumentException.class, () -> {
            Task6.findLocalMin(array);
        });

        String expectedMessage = "Array is empty";
        String actualMessage = exception.getMessage();

        assertTrue(actualMessage.contains(expectedMessage));
    }
}