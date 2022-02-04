import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Task11Test1 {

    @Test
    void findOutOfRange() {
        double min = 3.0;
        double max = 1.0;
        double[] array = {2.3, 5.0, 0.99};

        Exception exception = assertThrows(IllegalArgumentException.class, () -> {
            Task11.findOutOfRange(min, max, array);
        });

        String expectedMessage = "Max cannot be less than Min";
        String actualMessage = exception.getMessage();

        assertTrue(actualMessage.contains(expectedMessage));
    }
}