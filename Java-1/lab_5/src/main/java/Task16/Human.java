package Task16;

import java.util.Objects;

/**
 * Abstract class that describes Human in Formal style
 *
 * @author Shkolenko
 * @version 1.0
 */
public abstract class Human implements Formal {

    /** Human's surname */
    private String surname;

    /** Human's name */
    private String name;

    /** Human's patronymic */
    private String patronymic;

    /** Human's birthday */
    private String birthday;

    /** Human's gender */
    private Genders gender;

    /** Human's homeAddress */
    private String homeAddress;

    /**
     * @param surname Human's surname
     * @param name Human's name
     * @param patronymic Human's patronymic
     * @param birthday Human's birthday
     * @param gender Human's gender
     * @param homeAddress Human's homeAddress
     */
    public Human(String surname, String name, String patronymic,
                 String birthday, Genders gender, String homeAddress) {
        setSurname(surname);
        setName(name);
        setPatronymic(patronymic);
        setBirthday(birthday);
        setGender(gender);
        setHomeAddress(homeAddress);
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        if (surname.isEmpty()) {
            throw new IllegalArgumentException("the surname cannot be empty");
        }
        this.surname = surname;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name.isEmpty()) {
            throw new IllegalArgumentException("the name cannot be empty");
        }
        this.name = name;
    }

    public String getPatronymic() {
        return patronymic;
    }

    public void setPatronymic(String patronymic) {
        if (patronymic.isEmpty()) {
            throw new IllegalArgumentException("the patronymic cannot be empty");
        }
        this.patronymic = patronymic;
    }

    public String getBirthday() {
        return birthday;
    }

    public void setBirthday(String birthday) {
        DateValidator validator = new DateFormatValidator("dd.MM.yyyy");
        if (!validator.isValid(birthday)) {
            throw new IllegalArgumentException("invalid birthday");
        }
        this.birthday = birthday;
    }

    public Genders getGender() {
        return gender;
    }

    public void setGender(Genders gender) {
        this.gender = gender;
    }

    public String getHomeAddress() {
        return homeAddress;
    }

    public void setHomeAddress(String homeAddress) {
        if (homeAddress.isEmpty()) {
            throw new IllegalArgumentException("the homeAddress cannot be empty");
        }
        this.homeAddress = homeAddress;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Human human = (Human) o;
        return surname.equals(human.surname)
                && homeAddress.equals(human.homeAddress);
    }

    @Override
    public int hashCode() {
        return Objects.hash(surname, homeAddress);
    }

    @Override
    public String toString() {
        return "Surname: " + surname + ", Name: " + name + ", Patronymic: "
                + patronymic + "\nBirthday: " + birthday + ", Gender: " + gender
                + "\nHome address: " + homeAddress;
    }
}
