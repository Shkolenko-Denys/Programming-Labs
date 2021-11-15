package Task5;

import java.util.Scanner;

public class Task5 {
    /**
     * Построить программу для работы с классом для хранения данных о сообщении
     * на форуме (автор, тема, текст, время, дата создания и редактирование).
     * Программа должна обеспечивать простейшие функции: ввод значений,
     * редактирование, вывод значений.
     * */

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("Author: ");
        String author = in.nextLine();
        System.out.print("Topic: ");
        String topic = in.nextLine();
        System.out.print("Text: ");
        String text = in.nextLine();

        Message message = new Message(author, topic, text);
        System.out.println(message);

        System.out.print("New text: ");
        String newText = in.nextLine();

        message.setText(newText);
        System.out.println(message);
    }
}
