package Task40;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Task40 {
    /**
     * Создайте класс Дробь (числитель, знаменатель, арифметические операции,
     * преобразование в вещественный тип) и на его основе класс
     * Число с дробной частью.
     * */

    private static int input_number(String name) {
        Scanner in = new Scanner(System.in);
        int number;

        while (true) {
            System.out.print(name + ": ");
            try {
                number = in.nextInt();
                in.nextLine();  // for '\n'
                return number;
            } catch (InputMismatchException e) {
                in.nextLine();  // for '\n'
                System.out.println(" Error: " + e);
            }
        }
    }

    public static void main(String[] args) {
        int numerator = input_number("numerator");
        int denominator = input_number("denominator");

        try {
            Fraction fraction = new Fraction(numerator, denominator);
            System.out.println(fraction);
            System.out.println(fraction.get_float());
        } catch (IllegalArgumentException e) {
            System.out.println(" Error: " + e);
            System.exit(1);
        }

        int whole = input_number("whole");

        try {
            FractionNumber fractionNumber = new FractionNumber(whole, numerator,
                    denominator);
            System.out.println(fractionNumber);
            System.out.println(fractionNumber.get_float());
        } catch (IllegalArgumentException e) {
            System.out.println(" Error: " + e);
            System.exit(1);
        }
    }
}
