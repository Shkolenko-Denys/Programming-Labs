package Task1;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Task1 {
    /**
     * Построить программу для работы с классом для хранения данных о кривой
     * второго порядка - гиперболе. Программа должна обеспечивать:
     * расчет у по х и наоборот, ввод значений, вывод значений.
     * */

    private static double input_number(String name) {
        Scanner in = new Scanner(System.in);
        double number;

        while (true) {
            System.out.print("Enter the '" + name + "': ");
            try {
                number = in.nextDouble();
                in.nextLine();  // for '\n'
                return number;
            } catch (InputMismatchException e) {
                in.nextLine();  // for '\n'
                System.out.println(" Error: " + e);
            }
        }
    }

    public static void main(String[] args) {
        double a = input_number("a");
        double b = input_number("b");
        try {
            Hyperbola hyperbola = new Hyperbola(a, b);
            System.out.println(hyperbola);

            double x = input_number("x");
            System.out.println("y = " + hyperbola.getYbyX(x));

            double y = input_number("y");
            System.out.println("x = " + hyperbola.getXbyY(y));
        } catch (IllegalArgumentException e) {
            System.out.println(" Error: " + e);
        }
    }
}
