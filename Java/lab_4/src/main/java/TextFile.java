public class TextFile {

    private String path;
    private String description;

    public TextFile(String path, String description) {
        this.setPath(path);
        this.setDescription(description);
    }

    public void setPath(String path) throws IllegalArgumentException {
        if (path.isEmpty()) {
            throw new IllegalArgumentException("path cannot be empty");
        }
        this.path = path;
    }

    public String getPath() {
        return path;
    }

    public void setDescription(String description) throws IllegalArgumentException {
        if (description.isEmpty()) {
            throw new IllegalArgumentException("description cannot be empty");
        }
        this.description = description;
    }

    public String getDescription() {
        return description;
    }

    @Override
    public String toString() {
        return path + " " + description;
    }
}
