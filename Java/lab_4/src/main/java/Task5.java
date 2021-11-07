import java.util.*;

public class Task5 {
    /**
     * Создайте приложение для просмотра списка книг и удаления книг в библиотечном каталоге.
     * Записи в списке (5 записей) являются объектами класса HashMap, где ключом является индекс
     * ISBN книги (типа Integer), а значением – объект Book, содержащий наименование книги,
     * фамилию, имя и отчество (ФИО) автора, издательство (все поля типа String), год издания
     * (типа int) и цену книги (типа float). Предусмотреть возможность сортировки книг по 2-3 полям.
     * */

    private static final Map<Long, Book> library = new HashMap<>();

    private static long getISBN() throws IllegalArgumentException {
        Scanner in = new Scanner(System.in);
        System.out.print("ISBN: ");
        long isbn = in.nextLong();
        in.nextLine();  // for '\n'
        if (isbn <= 0 || isbn > 1e13 - 1) {
            throw new IllegalArgumentException("incorrect ISBN");
        }
        return isbn;
    }

    private static void addBook() throws IllegalArgumentException {
        Scanner in = new Scanner(System.in);
        long isbn = getISBN();

        System.out.print("Title: ");
        String title = in.nextLine();
        System.out.print("Author surname: ");
        String authorSurname = in.nextLine();
        System.out.print("Author name: ");
        String authorName = in.nextLine();
        System.out.print("Author patronymic: ");
        String authorPatronymic = in.nextLine();
        System.out.print("Publishing house: ");
        String publishingHouse = in.nextLine();
        System.out.print("Year: ");
        int year = in.nextInt();
        System.out.print("Price: ");
        float price = in.nextFloat();

        library.put(isbn, new Book(title, authorSurname, authorName, authorPatronymic,
                publishingHouse, year, price));
    }

    private static void removeBook() {
        long isbn = getISBN();
        library.remove(isbn);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int mode;

        while (true) {
            System.out.println("""
                Choose mode:
                0 -- add a new book
                1 -- show the list sorted by isbn
                2 -- show the list sorted by author surname
                3 -- show the list sorted by price
                4 -- remove book
                5 -- exit""");
            System.out.print("Enter the mode: ");

            try {
                mode = in.nextInt();
                in.nextLine();  // for '\n'
                switch (mode) {
                    case 0 -> addBook();
                    case 1 -> library.entrySet()
                            .stream()
                            .sorted(Map.Entry.comparingByKey())
                            .forEach(System.out::println);
                    case 2 -> library.entrySet()
                            .stream()
                            .sorted(Comparator.comparing(o -> o.getValue().getAuthorSurname()))
                            .forEach(System.out::println);
                    case 3 -> library.entrySet()
                            .stream()
                            .sorted(Comparator.comparing(o -> o.getValue().getPrice()))
                            .forEach(System.out::println);
                    case 4 -> removeBook();
                    case 5 -> System.exit(0);
                    default -> throw new IllegalArgumentException("incorrect mode");
                }
            } catch (InputMismatchException e) {
                in.nextLine();  // for '\n'
                System.out.println("Error: " + e);
            } catch (Exception e) {
                System.out.println("Error: " + e);
            }
            System.out.println();
        }
    }
}
