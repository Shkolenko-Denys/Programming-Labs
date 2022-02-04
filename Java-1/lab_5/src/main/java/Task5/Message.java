package Task5;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Objects;

/**
 * Class that describes Message in forum.
 *
 * @author Shkolenko
 * @version 1.0
 */
public class Message implements Readable, Writeable {

    /** The author of the message */
    private String author;

    /** The topic of the message */
    private String topic;

    /** The text of the message */
    private String text;

    /** The date of the creating message */
    private final String created;

    /** The date of the editing message */
    private String edited;

    /**
     * @param author author of the message
     * @param topic topic of the message
     * @param text text of the message
     */
    public Message(String author, String topic, String text) {
        setAuthor(author);
        setTopic(topic);
        setText(text);
        this.created = LocalDateTime.now().format(DateTimeFormatter
                .ofPattern("dd-MM-yyyy HH:mm:ss"));
    }

    /**
     * @return author of the message
     */
    public String getAuthor() {
        return author;
    }

    /**
     * @param author new author
     */
    public void setAuthor(String author) {
        if (author.isEmpty()) {
            throw new IllegalArgumentException("the author cannot be empty");
        }
        this.author = author;
    }

    /**
     * @return topic of the message
     */
    public String getTopic() {
        return topic;
    }

    /**
     * @param topic new topic
     */
    public void setTopic(String topic) {
        if (topic.isEmpty()) {
            throw new IllegalArgumentException("the topic cannot be empty");
        }
        this.topic = topic;
    }

    /**
     * @return text of the message
     */
    public String getText() {
        return text;
    }

    /**
     * @param text new text
     */
    public void setText(String text) {
        if (text.isEmpty()) {
            throw new IllegalArgumentException("the text cannot be empty");
        }
        this.edited = LocalDateTime.now().format(DateTimeFormatter
                .ofPattern("dd-MM-yyyy HH:mm:ss"));
        this.text = text;
    }

    /**
     * @return date when created
     */
    public String getCreated() {
        return created;
    }

    /**
     * @return date when edited
     */
    public String getEdited() {
        return edited;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Message message = (Message) o;
        return text.equals(message.text);
    }

    @Override
    public int hashCode() {
        return Objects.hash(text);
    }

    @Override
    public String toString() {
        return "Author: " + author + ", Topic: " + topic
                + "\nText: " + text
                + "\nCreated: " + created + ", Edited: " + edited;
    }
}
