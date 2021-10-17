import org.junit.jupiter.api.Test;

import java.util.HashMap;

import static org.junit.jupiter.api.Assertions.*;

class Task11Test2 {

    @Test
    void findOutOfRange() {
        double min = 1.0;
        double max = 10.0;
        double[] array = {};

        Exception exception = assertThrows(IllegalArgumentException.class, () -> {
            Task11.findOutOfRange(min, max, array);
        });

        String expectedMessage = "Array is empty";
        String actualMessage = exception.getMessage();

        assertTrue(actualMessage.contains(expectedMessage));
    }
}