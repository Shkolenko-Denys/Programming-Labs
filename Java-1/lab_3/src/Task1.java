public class Task1 {
    /**
     * Вывести таблицу преобразований целых десятичных чисел в интервале от 10 до 100 с шагом 20
     * в 16-ное представление.
     * */

    public static void main(String[] args) {
        for (int i = 10; i < 100; i += 20) {
            System.out.println(i + " = " + Integer.toHexString(i));
        }
    }
}
