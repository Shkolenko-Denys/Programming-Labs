package Task16;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Task16 {
    /**
     * Написать класс для отдела кадров Сотрудник (поля: фамилия, имя,
     * отчество, дата рождения, пол, образования, номер документа об
     * образовании, учебное заведение выдавшее документ, дата поступления
     * на работу, домашний адрес).
     * */

    private static int input_int(String name) {
        Scanner in = new Scanner(System.in);
        int number;

        while (true) {
            System.out.print("Enter the '" + name + "': ");
            try {
                number = in.nextInt();
                in.nextLine();  // for '\n'
                return number;
            } catch (InputMismatchException e) {
                in.nextLine();  // for '\n'
                System.out.println(" Error: " + e);
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("Surname: ");
        String surname = in.nextLine();

        System.out.print("Name: ");
        String name = in.nextLine();

        System.out.print("Patronymic: ");
        String patronymic = in.nextLine();

        System.out.print("Birthday: ");
        String birthday = in.nextLine();

        System.out.println("""
                0 -- man
                other number -- woman""");
        int number = input_int("Gender");
        Genders gender;
        if (number == 0) {
            gender = Genders.MAN;
        } else {
            gender = Genders.WOMAN;
        }

        System.out.println("""
                0 -- Early childhood education
                1 -- Primary education
                2 -- Lower secondary education
                3 -- Upper secondary education
                4 -- Bachelor's
                5 -- Master's
                other number -- Doctorate""");

        number = input_int("Education");

        EducationLevels education;
        switch (number) {
            case 0 -> education = EducationLevels.EARLY_CHILDHOOD;
            case 1 -> education = EducationLevels.PRIMARY;
            case 2 -> education = EducationLevels.LOWER_SECONDARY;
            case 3 -> education = EducationLevels.UPPER_SECONDARY;
            case 4 -> education = EducationLevels.BACHELOR;
            case 5 -> education = EducationLevels.MASTER;
            default -> education = EducationLevels.DOCTORATE;
        }

        int educationDocId = input_int("Education document id");
        System.out.print("Institute: ");
        String institute = in.nextLine();

        System.out.print("Home address: ");
        String homeAddress = in.nextLine();

        Employee employee = new Employee(surname, name, patronymic, birthday,
                gender, homeAddress, education, educationDocId, institute);

        System.out.println(employee);
    }
}
