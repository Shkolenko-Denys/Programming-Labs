import java.util.*;

public class Task16 {
    /**
     * Создайте приложение для просмотра списка товаров и изменения цены товара в электронном
     * магазине. Список товаров (5 записей) создается в программе и является объектом класса
     * TreeMap. Ключом записи является артикул товара marking (типа Integer), а значением –
     * объект Article, содержащий наименование товара (типа String) и цену товара (типа float).
     * Предусмотреть возможность проверки уникальности наименования товара с помощью HashSet.
     * */

    private static final Map<Integer, Article> store = new TreeMap<>();
    private static final HashSet<String> storeSetOfNames = new HashSet<>();

    private static void addArticle() throws IllegalArgumentException {
        Scanner in = new Scanner(System.in);

        System.out.print("Marking: ");
        int marking = in.nextInt();
        in.nextLine();  // for '\n'
        if (marking <= 0) {
            throw new IllegalArgumentException("incorrect marking");
        }
        System.out.print("Name: ");
        String name = in.nextLine();
        System.out.print("Price: ");
        float price = in.nextFloat();

        if (storeSetOfNames.add(name)) {
            store.put(marking, new Article(name, price));
        } else {
            throw new IllegalArgumentException("The name of the article already exists");
        }
    }

    private static void editPrice() throws IllegalArgumentException {
        Scanner in = new Scanner(System.in);

        System.out.print("Marking: ");
        int marking = in.nextInt();
        in.nextLine();  // for '\n'
        if (marking <= 0) {
            throw new IllegalArgumentException("incorrect marking");
        }
        System.out.print("New price: ");
        float newPrice = in.nextFloat();

        store.get(marking).setPrice(newPrice);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int mode;

        while (true) {
            System.out.println("""
                Choose mode:
                0 -- add a new article
                1 -- show the list of articles
                2 -- edit price of some article
                3 -- exit""");
            System.out.print("Enter the mode: ");

            try {
                mode = in.nextInt();
                in.nextLine();  // for '\n'
                switch (mode) {
                    case 0 -> addArticle();
                    case 1 -> {
                        for (Map.Entry<Integer, Article> entry : store.entrySet()) {
                            System.out.println("Marking: " + entry.getKey() + ". Article: " +
                                    entry.getValue());
                        }
                    }
                    case 2 -> editPrice();
                    case 3 -> System.exit(0);
                    default -> throw new IllegalArgumentException("incorrect mode");
                }
            } catch (InputMismatchException e) {
                in.nextLine();  // for '\n'
                System.out.println("Error: " + e);
            } catch (NullPointerException e) {
                System.out.println("Error: File does not exist");
            } catch (Exception e) {
                System.out.println("Error: " + e);
            }
            System.out.println();
        }
    }
}
