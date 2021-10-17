import java.util.Arrays;

public class Task1 {
    /**
     * Сформировать и вывести на дисплей одномерный массив b, в котором первыми элементами являются
     * элементы исходного одномерного массива a с отрицательными значениями (с сохранением порядка
     * следования), а затем элементы a с нулевыми и положительными значениями.
     * */

    public static double[] getFinalArray(double[] originalArray) {
        double[] finalArray = new double[originalArray.length];
        int i = 0;
        for (double v : originalArray) {
            if (v < 0.0) {
                finalArray[i++] = v;
            }
        }
        double eps = 1e-7;
        for (double v : originalArray) {
            if (Math.abs(v) < eps) {
                finalArray[i++] = 0.0;
            }
        }
        for (double v : originalArray) {
            if (v > 0.0) {
                finalArray[i++] = v;
            }
        }
        return finalArray;
    }

    public static void main(String[] args) {
        double[] originalArray;
        double[] finalArray;
        try {
            originalArray = Arrays.stream(args).mapToDouble(Double::parseDouble).toArray();
            finalArray = getFinalArray(originalArray);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
            return;
        }

        System.out.print("Original array: ");
        System.out.println(Arrays.toString(originalArray));
        System.out.print("Final array: ");
        System.out.println(Arrays.toString(finalArray));
    }
}
