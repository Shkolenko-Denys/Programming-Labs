package Task5;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MessageTest {

    @Test
    void setAuthor() {
        Exception exception = assertThrows(IllegalArgumentException.class, () ->
                new Message("", "topic", "text"));

        String expectedMessage = "the author cannot be empty";
        String actualMessage = exception.getMessage();

        assertTrue(actualMessage.contains(expectedMessage));
    }

    @Test
    void setTopic() {
        Exception exception = assertThrows(IllegalArgumentException.class, () ->
                new Message("author", "", "text"));

        String expectedMessage = "the topic cannot be empty";
        String actualMessage = exception.getMessage();

        assertTrue(actualMessage.contains(expectedMessage));
    }

    @Test
    void setText() {
        Exception exception = assertThrows(IllegalArgumentException.class, () ->
                new Message("author", "topic", ""));

        String expectedMessage = "the text cannot be empty";
        String actualMessage = exception.getMessage();

        assertTrue(actualMessage.contains(expectedMessage));
    }
}