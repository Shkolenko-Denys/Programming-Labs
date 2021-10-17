public class Task7 {
    /*
    Дана площадь квадрата. Найти сторону данного квадрата и минимальную
    сторону квадрата, в который исходный квадрат может быть вписан.
    */

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Missed argument.");
            return;
        }

        try {
            int s = Integer.parseInt(args[0]);
            if (s <= 0) {
                System.out.println("The integer must be positive.");
                return;
            }

            double a = Math.sqrt(s);
            double min_new = 2.0 * a / Math.sqrt(2.0);

            System.out.printf(" a = %.3f\n min_new = %.3f\n", a, min_new);
        } catch (NumberFormatException nfe) {
            System.out.println("The argument must be integer.");
        }
    }
}
