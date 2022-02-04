import java.util.*;

public class Task30 {
    /**
     * Создайте приложение для поиска в списке файлов и удаления файла из списка.
     * Список (для 5 текстовых файлов с расширением .txt) создается в программе и является
     * объектом класса HashMap, где ключом является имя файла (типа String), а значением –
     * объект типа TextFile, содержащий два элемента String – абсолютный путь к файлу
     * (без имени файла) и краткое описание содержимого файла.
     * */

    private static final Map<String, TextFile> listFiles = new HashMap<>();

    private static void addTextFile() throws IllegalArgumentException {
        Scanner in = new Scanner(System.in);

        System.out.print("Name: ");
        String name = in.nextLine();
        System.out.print("Path: ");
        String path = in.nextLine();
        System.out.print("Description: ");
        String description = in.nextLine();

        listFiles.put(name, new TextFile(path, description));
    }

    private static void removeTextFile() {
        Scanner in = new Scanner(System.in);
        System.out.print("Name: ");
        String name = in.nextLine();
        listFiles.remove(name);
    }

    private static void findTextFile() {
        Scanner in = new Scanner(System.in);
        System.out.print("Name: ");
        String name = in.nextLine();

        System.out.println(" Path: " + listFiles.get(name).getPath());
        System.out.println(" Description: " + listFiles.get(name).getDescription());
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int mode;

        while (true) {
            System.out.println("""
                Choose mode:
                0 -- add a new text file
                1 -- show the list of files
                2 -- find a text file and show information
                3 -- remove a text file
                4 -- exit""");
            System.out.print("Enter the mode: ");

            try {
                mode = in.nextInt();
                in.nextLine();  // for '\n'
                switch (mode) {
                    case 0 -> addTextFile();
                    case 1 -> listFiles.entrySet()
                            .stream()
                            .sorted(Map.Entry.comparingByKey())
                            .forEach(System.out::println);
                    case 2 -> findTextFile();
                    case 3 -> removeTextFile();
                    case 4 -> System.exit(0);
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
