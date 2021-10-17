import java.util.HashSet;
import java.util.Scanner;

public class Task16 {
    /**
     * Выведите на дисплей значения тех элементы массивов a и b, которые есть только в одном из
     * массивов, и отсутствуют в другом массиве (предполагается, что и массив a и массив b
     * являются множествами, т.е. каждый из них не содержит элементов с одинаковыми значениями).
     * */

    public static HashSet<Integer>
    symmetricDiff(HashSet<Integer> set1, HashSet<Integer> set2) {
        HashSet<Integer> union = new HashSet<>(set1);
        union.addAll(set2);

        HashSet<Integer> intersection = new HashSet<>(set1);
        intersection.retainAll(set2);

        union.removeAll(intersection);
        return union;
    }

    public static void main(String[] args) {
        HashSet<Integer> set1 = new HashSet<>();
        HashSet<Integer> set2 = new HashSet<>();
        Scanner in = new Scanner(System.in);

        System.out.print("Set #1 : ");
        String[] inputSet1 = in.nextLine().split(" ");
        System.out.print("Set #2 : ");
        String[] inputSet2 = in.nextLine().split(" ");

        HashSet<Integer> symmetricDiff;

        try {
            for (String item : inputSet1) {
                set1.add(Integer.parseInt(item));
            }
            for (String item : inputSet2) {
                set2.add(Integer.parseInt(item));
            }
            symmetricDiff = symmetricDiff(set1, set2);
        } catch (NumberFormatException e) {
            System.out.println("Error: " + e.getMessage());
            return;
        }

        System.out.print("Symmetric difference: ");
        for (Integer item : symmetricDiff) {
            System.out.print(item + " ");
        }
    }
}
