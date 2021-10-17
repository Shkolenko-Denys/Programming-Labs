public class Task19 {
    /*
    Даны 4 целых стороны и диагональ выпуклого четырехугольника.
    Найти его площадь (рассмотрев 2 треугольника).
    */

    public static void main(String[] args) {
        if (args.length < 5) {
            System.out.println("Not enough arguments. Five arguments expected.");
            return;
        }

        try {
            int a = Integer.parseInt(args[0]);
            int b = Integer.parseInt(args[1]);
            int c = Integer.parseInt(args[2]);
            int d = Integer.parseInt(args[3]);
            double diag = Double.parseDouble(args[4]);

            double s = 0;
            if ((a + b > diag) && (a + diag > b) && (b + diag > a)) {
                if ((c + d > diag) && (c + diag > d) && (d + diag > c)) {
                    double p1 = (a + b + diag) / 2.0;
                    double p2 = (c + d + diag) / 2.0;
                    double s1 = Math.sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - diag));
                    double s2 = Math.sqrt(p2 * (p2 - c) * (p2 - d) * (p2 - diag));
                    s = s1 + s2;
                }
            }

            if (s == 0) {
                System.out.println("This quadrangle doesn't exist.");
            } else {
                System.out.println(" s = " + s);
            }
        } catch (NumberFormatException nfe) {
            System.out.println("The first four arguments must be integers.\n" +
                    "The fifth argument must be double.");
        }
    }
}
