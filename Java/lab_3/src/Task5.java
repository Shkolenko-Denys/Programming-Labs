import java.util.InputMismatchException;
import java.util.Scanner;

public class Task5 {
    /**
     * Создайте программу для шифрования\расшифровки текста методом Цезаря. В нем ключом является
     * целое число, а шифрование\расшифровка заключается в суммировании\ вычитании кодов символов
     * открытого текста\криптотекста с ключом.
     * */

    private static String encryptionCaesar(String text, int key) {
        char[] chars = text.toCharArray();
        for (int i = 0; i < text.length(); i++) {
            char c = chars[i];
            if (c >= 32 && c <= 126) {
                int x = c - 32;
                x = (x + key) % 95;
                if (x < 0) {
                    x += 95;
                }
                chars[i] = (char) (x + 32);
            }
        }
        return new String(chars);
    }

    private static String decryptionCaesar(String text, int key) {
        return encryptionCaesar(text, -key);
    }

    public static void main(String[] args) {
        System.out.println("Input text:");
        Scanner in = new Scanner(System.in);
        String inputString = in.nextLine();

        System.out.print("Enter the key: ");
        int key;
        try {
            key = in.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("The key must be integer type");
            return;
        }
        in.nextLine();  // for '\n'

        String outputString = encryptionCaesar(inputString, key);
        System.out.println("\nOutput text:\n" + outputString);

        String originalString = decryptionCaesar(outputString, key);
        System.out.println("\nOriginal text:\n" + originalString);
    }
}
