public class Article {

    private String name;
    private float price;

    public Article(String name, float price) {
        this.setName(name);
        this.setPrice(price);
    }

    public void setName(String name) throws IllegalArgumentException {
        if (name.isEmpty()) {
            throw new IllegalArgumentException("name cannot be empty");
        }
        this.name = name;
    }

    public String getName() {
        return name;
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
        return name + " " + price + "$";
    }
}
