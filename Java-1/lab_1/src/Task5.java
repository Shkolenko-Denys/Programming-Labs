public class Task5 {
    /*
    Пусть даны длины сторон треугольника. Найдите его площадь и полупериметр.
    */

    public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println("Not enough arguments. Three arguments expected.");
            return;
        }

        try {
            int a = Integer.parseInt(args[0]);
            int b = Integer.parseInt(args[1]);
            int c = Integer.parseInt(args[2]);

            if ((a + b > c) && (b + c > a) && (a + c > b)) {
                double p = (a + b + c) / 2.0;
                double s = Math.sqrt(p * (p - a) * (p - b) * (p - c));
                System.out.printf(" p = %.3f\n s = %.3f\n", p, s);
            } else {
                System.out.println("This triangle doesn't exist.");
            }
        } catch (NumberFormatException nfe) {
            System.out.println("The arguments must be integers.");
        }
    }
}
