import java.util.InputMismatchException;
import java.util.Scanner;

public class Task40 {
    /**
     * Создайте класс Дробь (числитель, знаменатель, арифметические операции,
     * преобразование в вещественный тип) и на его основе класс
     * Число с дробной частью.
     * */

    public static int input_int(String name) {
        Scanner in = new Scanner(System.in);
        int number;

        while (true) {
            System.out.print("Enter the '" + name + "': ");
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
        int numerator = input_int("numerator");
        int denominator = input_int("denominator");

        try {
            Fraction fraction = new Fraction(numerator, denominator);
            System.out.println(fraction);
            System.out.println(fraction.get_float());
        } catch (IllegalArgumentException e) {
            System.out.println(" Error: " + e);
            System.exit(1);
        }

        int whole = input_int("whole");

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
