import java.util.InputMismatchException;
import java.util.Scanner;

public class Task21 {
    /**
     * Проверьте, не является ли значения i-ых элементов массива a линейной комбинацией i-ых
     * значений элементов массива b, т.е. ai = k*bi + c, где k и c – константы (значения k и c можно
     * определить из значений двух первых элементов a и b как два уравнения с двумя неизвестными).
     * */

    public static boolean linearCombination(double[] array1, double[] array2) {
        if (array1.length < 2) {
            throw new IllegalArgumentException("Array length must be 2 or greater");
        }
        if (array1.length > array2.length) {
            throw new IllegalArgumentException("Must be array2.length >= array1.length");
        }
        double k = (array1[1] - array1[0]) / (array2[1] - array2[0]);
        double c = array1[0] - k * array2[0];

        double eps = 1e-7;
        for (int i = 2; i < array1.length; i++) {
            if (Math.abs(array1[i] - k * array2[i] - c) > eps) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double[] doubleArray1;
        double[] doubleArray2;

        try {
            System.out.print("Enter the array size: ");
            int size = in.nextInt();
            in.nextLine();  // read '\n'

            System.out.print("Array #1 : ");
            String[] stringArray1 = in.nextLine().split(" ");
            System.out.print("Array #2 : ");
            String[] stringArray2 = in.nextLine().split(" ");

            doubleArray1 = new double[size];
            doubleArray2 = new double[size];

            for (int i = 0; i < size; i++) {
                doubleArray1[i] = Double.parseDouble(stringArray1[i]);
                doubleArray2[i] = Double.parseDouble(stringArray2[i]);
            }

            System.out.println("Result:");
            if (linearCombination(doubleArray1, doubleArray2)) {
                System.out.println("  Yes, the values are a linear combination");
            } else {
                System.out.println("  No, the values are not a linear combination");
            }
        } catch (InputMismatchException e) {
            System.out.println("Error: Size must be integer type");
        } catch (NegativeArraySizeException e) {
            System.out.println("Error: Array size cannot be negative");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Not enough elements entered for the arrays");
        } catch (NumberFormatException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
