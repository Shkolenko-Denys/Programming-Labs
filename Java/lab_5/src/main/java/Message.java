import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Objects;

public class Message implements Readable, Writeable {

    private String author;
    private String topic;
    private String text;
    private final String created;
    private String edited;

    public Message(String author, String topic, String text) {
        this.author = author;
        this.topic = topic;
        this.text = text;
        this.created = LocalDateTime.now().format(DateTimeFormatter
                .ofPattern("dd-MM-yyyy HH:mm:ss"));
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        if (author.isEmpty()) {
            throw new IllegalArgumentException("the author cannot be empty");
        }
        this.author = author;
    }

    public String getTopic() {
        return topic;
    }

    public void setTopic(String topic) {
        if (topic.isEmpty()) {
            throw new IllegalArgumentException("the topic cannot be empty");
        }
        this.topic = topic;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        if (text.isEmpty()) {
            throw new IllegalArgumentException("the text cannot be empty");
        }
        this.edited = LocalDateTime.now().format(DateTimeFormatter
                .ofPattern("dd-MM-yyyy HH:mm:ss"));
        this.text = text;
    }

    public String getCreated() {
        return created;
    }

    public String getEdited() {
        return edited;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Message message = (Message) o;
        return author.equals(message.author) && topic.equals(message.topic)
                && text.equals(message.text);
    }

    @Override
    public int hashCode() {
        return Objects.hash(author, topic, text);
    }

    @Override
    public String toString() {
        return "Author: " + author + ", Topic: " + topic
                + "\nText: " + text
                + "\nCreated: " + created + ", Edited: " + edited;
    }
}
