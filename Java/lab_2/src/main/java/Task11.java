import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Task11 {
    /**
     * Определить индексы и значения элементов исходного одномерного массива A, величины которых
     * лежат вне задаваемой нижней Amin и верхней Amax границ (Ai < Amin или  Ai > Amax). Значения
     * Amin и Amax задаются как первые два аргумента при вызове программы, остальные аргументы –
     * элементы массива.
     * */

    public static HashMap<Integer, Double> findOutOfRange(double min, double max, double[] array) {
        HashMap<Integer, Double> outOfRange = new HashMap<>();
        if (max < min) {
            throw new IllegalArgumentException("Max cannot be less than Min");
        }
        if (array.length == 0) {
            throw new IllegalArgumentException("Array is empty");
        }

        for (int i = 0; i < array.length; i++) {
            if (array[i] < min || array[i] > max) {
                outOfRange.put(i, array[i]);
            }
        }
        return outOfRange;
    }

    public static void main(String[] args) {
        double[] doubleArray;
        String[] stringArray;
        double min, max;
        HashMap<Integer, Double> outOfRange;

        try {
            min = Double.parseDouble(args[0]);
            max = Double.parseDouble(args[1]);

            stringArray = Arrays.copyOfRange(args, 2, args.length);
            doubleArray = Arrays.stream(stringArray).mapToDouble(Double::parseDouble).toArray();

            outOfRange = findOutOfRange(min, max, doubleArray);
        }
        catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
            return;
        }

        ArrayList<Integer> keys = new ArrayList<>(outOfRange.keySet());
        ArrayList<Double> values = new ArrayList<>(outOfRange.values());

        System.out.println("Input:\n" +
                "  Min: " + min + " ; Max: " + max + "\n" +
                "  Array: " + Arrays.toString(doubleArray));
        System.out.println("Output:");
        for (int i = 0; i < outOfRange.size(); i++) {
            System.out.println("Index: " + keys.get(i) + " ; Value: " + values.get(i));
        }
    }
}
