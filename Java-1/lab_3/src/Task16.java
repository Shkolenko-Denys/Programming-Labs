public class Task16 {
    /**
     * Анализ типов аргументов, задаваемых при запуске программы. Если аргумент является правильным
     * целым числом (шаблон: одна или несколько цифр, первым символом может быть либо цифра,  либо
     * знак "+" или "-"), то  тип аргумента "Integer", иначе "String". Программа выводит количество
     * заданных аргументов и, для каждого аргумента, его тип и значение.
     * */

    public static void main(String[] args) {
        System.out.println("Amount: " + args.length);
        for (String num : args) {
            if (num.matches("[+-]?\\d+")) {
                System.out.println("Type: Integer ; Value: " + num);
            } else {
                System.out.println("Type: String ; Value: " + num);
            }
        }
    }
}
