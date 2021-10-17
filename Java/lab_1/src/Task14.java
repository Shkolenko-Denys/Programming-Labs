public class Task14 {
    /*
    Даны целые катеты прямоугольного треугольника, найти высоту и гипотенузу.
    */

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Not enough arguments. Two arguments expected.");
            return;
        }

        try {
            int a = Integer.parseInt(args[0]);
            int b = Integer.parseInt(args[1]);

            if ((a <= 0) || (b <= 0)) {
                System.out.println("The arguments must be positive.");
                return;
            }

            double c = Math.sqrt(a*a + b*b);
            double h = a * b / c;

            System.out.printf(" c = %.3f\n h = %.3f\n", c, h);
        } catch (NumberFormatException nfe) {
            System.out.println("The arguments must be integers.");
        }
    }
}
