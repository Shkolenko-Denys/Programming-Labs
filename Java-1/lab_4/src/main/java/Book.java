public class Book {

    private String title;
    private String authorSurname;
    private String authorName;
    private String authorPatronymic;
    private String publishingHouse;
    private int year;
    private float price;

    public Book(String title, String authorSurname, String authorName,
                   String authorPatronymic, String publishingHouse, int year, float price) {
        this.setTitle(title);
        this.setAuthorSurname(authorSurname);
        this.setAuthorName(authorName);
        this.setAuthorPatronymic(authorPatronymic);
        this.setPublishingHouse(publishingHouse);
        this.setYear(year);
        this.setPrice(price);
    }

    public void setTitle(String title) throws IllegalArgumentException {
        if (title.isEmpty()) {
            throw new IllegalArgumentException("title cannot be empty");
        }
        this.title = title;
    }

    public String getTitle() {
        return title;
    }

    public void setAuthorSurname(String authorSurname) throws IllegalArgumentException {
        if (authorSurname.isEmpty()) {
            throw new IllegalArgumentException("author surname cannot be empty");
        }
        this.authorSurname = authorSurname;
    }

    public String getAuthorSurname() {
        return authorSurname;
    }

    public void setAuthorName(String authorName) throws IllegalArgumentException {
        if (authorName.isEmpty()) {
            throw new IllegalArgumentException("author name cannot be empty");
        }
        this.authorName = authorName;
    }

    public String getAuthorName() {
        return authorName;
    }

    public void setAuthorPatronymic(String authorPatronymic) throws IllegalArgumentException {
        if (authorPatronymic.isEmpty()) {
            throw new IllegalArgumentException("author patronymic cannot be empty");
        }
        this.authorPatronymic = authorPatronymic;
    }

    public String getAuthorPatronymic() {
        return authorPatronymic;
    }

    public void setPublishingHouse(String publishingHouse) throws IllegalArgumentException {
        if (publishingHouse.isEmpty()) {
            throw new IllegalArgumentException("publishing house cannot be empty");
        }
        this.publishingHouse = publishingHouse;
    }

    public String getPublishingHouse() {
        return publishingHouse;
    }

    public void setYear(int year) throws IllegalArgumentException {
        if (year <= 0) {
            throw new IllegalArgumentException("year must be positive");
        }
        this.year = year;
    }

    public int getYear() {
        return year;
    }

    public void setPrice(float price) throws IllegalArgumentException {
        if (price < 0) {
            throw new IllegalArgumentException("price cannot be negative");
        }
        this.price = price;
    }

    public float getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return title + " " + authorSurname + " " + authorName + " " + authorPatronymic + " "
                + publishingHouse + " " + year + " " + price + "$";
    }
}
