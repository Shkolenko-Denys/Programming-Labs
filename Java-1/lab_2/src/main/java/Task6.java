import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Task6 {
    /**
     * Определить значения и индексы локальных минимумов  исходного  одномерного массива a
     * (элемент массива называется локальным минимумом, если он строго меньше своих соседей).
     * */

    public static HashMap<Integer, Double> findLocalMin(double[] array) {
        HashMap<Integer, Double> localMin = new HashMap<>();
        int len = array.length;

        if (len == 0) {
            throw new IllegalArgumentException("Array is empty");
        }
        if (len == 1) {
            localMin.put(0, array[0]);
            return localMin;
        }

        if (array[0] < array[1]) {
            localMin.put(0, array[0]);
        }
        for (int i = 1; i < len - 1; i++) {
            if (array[i] < array[i - 1] && array[i] < array[i + 1]) {
                localMin.put(i, array[i]);
            }
        }
        if (array[len - 1] < array[len - 2]) {
            localMin.put(len - 1, array[len - 1]);
        }
        return localMin;
    }

    public static void main(String[] args) {
        double[] array;
        HashMap<Integer, Double> localMin;

        try {
            array = Arrays.stream(args).mapToDouble(Double::parseDouble).toArray();
            localMin = findLocalMin(array);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
            return;
        }

        ArrayList<Integer> keys = new ArrayList<>(localMin.keySet());
        ArrayList<Double> values = new ArrayList<>(localMin.values());

        System.out.println("Input: " + Arrays.toString(array));
        System.out.println("Output:");
        for (int i = 0; i < localMin.size(); i++) {
            System.out.println("Index: " + keys.get(i) + " ; Value: " + values.get(i));
        }
    }
}
