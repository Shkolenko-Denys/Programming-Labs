import java.util.*;

public class Task1 {
    /**
     * Создайте приложение для добавления абонента и просмотра списка абонентов телефонной сети.
     * Записи в списке (5 записей) создаются в программе и являются объектами класса HashMap,
     * где ключом является номер телефона (типа Integer), а значением – объект Abonent, содержащий
     * четыре значения типа String:  фамилию, имя, отчество и адрес. Предусмотреть возможность
     * сортировки элементов коллекции по 2-3 полям.
     * */

    private static final Map<Long, Abonent> notebook = new HashMap<>();

    private static void addAbonent() throws IllegalArgumentException {
        Scanner in = new Scanner(System.in);

        System.out.print("Phone number: ");
        long phoneNumber = in.nextLong();
        in.nextLine();  // for '\n'
        if (phoneNumber < 38e10 || phoneNumber > 39e10 - 1) {
            throw new IllegalArgumentException("incorrect phone number");
        }

        System.out.print("Surname: ");
        String surname = in.nextLine();
        System.out.print("Name: ");
        String name = in.nextLine();
        System.out.print("Patronymic: ");
        String patronymic = in.nextLine();
        System.out.print("Address: ");
        String address = in.nextLine();

        notebook.put(phoneNumber, new Abonent(surname, name, patronymic, address));
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int mode;

        while (true) {
            System.out.println("""
                Choose mode:
                0 -- add a new abonent
                1 -- show the list sorted by phone number
                2 -- show the list sorted by surname
                3 -- show the list sorted by name
                4 -- exit""");
            System.out.print("Enter the mode: ");

            try {
                mode = in.nextInt();
                in.nextLine();  // for '\n'
                switch (mode) {
                    case 0 -> addAbonent();
                    case 1 -> notebook.entrySet()
                            .stream()
                            .sorted(Map.Entry.comparingByKey())
                            .forEach(System.out::println);
                    case 2 -> notebook.entrySet()
                            .stream()
                            .sorted(Comparator.comparing(o -> o.getValue().getSurname()))
                            .forEach(System.out::println);
                    case 3 -> notebook.entrySet()
                            .stream()
                            .sorted(Comparator.comparing(o -> o.getValue().getName()))
                            .forEach(System.out::println);
                    case 4 -> System.exit(0);
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
