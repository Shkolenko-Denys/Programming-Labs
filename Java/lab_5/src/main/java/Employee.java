import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Objects;

public class Employee {

    private String surname;
    private String name;
    private String patronymic;
    private String birthday;
    private Genders gender;
    private EducationLevels education;
    private int educationDocId;
    private String institute;
    private final String dateOfEmployment;
    private String homeAddress;

    public Employee(String surname, String name, String patronymic,
                    String birthday, Genders gender, EducationLevels education,
                    int educationDocId, String institute, String homeAddress) {
        this.surname = surname;
        this.name = name;
        this.patronymic = patronymic;
        this.birthday = birthday;
        this.gender = gender;
        this.education = education;
        this.educationDocId = educationDocId;
        this.institute = institute;
        this.dateOfEmployment = LocalDateTime.now().format(DateTimeFormatter
                .ofPattern("dd.MM.yyyy"));
        this.homeAddress = homeAddress;
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

    public EducationLevels getEducation() {
        return education;
    }

    public void setEducation(EducationLevels education) {
        this.education = education;
    }

    public int getEducationDocId() {
        return educationDocId;
    }

    public void setEducationDocId(int educationDocId) {
        if (educationDocId <= 0) {
            throw new IllegalArgumentException("invalid document id");
        }
        this.educationDocId = educationDocId;
    }

    public String getInstitute() {
        return institute;
    }

    public void setInstitute(String institute) {
        if (institute.isEmpty()) {
            throw new IllegalArgumentException("the institute cannot be empty");
        }
        this.institute = institute;
    }

    public String getDateOfEmployment() {
        return dateOfEmployment;
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
        Employee employee = (Employee) o;
        return educationDocId == employee.educationDocId
                && surname.equals(employee.surname)
                && name.equals(employee.name)
                && patronymic.equals(employee.patronymic)
                && birthday.equals(employee.birthday)
                && gender == employee.gender
                && education == employee.education
                && institute.equals(employee.institute)
                && dateOfEmployment.equals(employee.dateOfEmployment)
                && homeAddress.equals(employee.homeAddress);
    }

    @Override
    public int hashCode() {
        return Objects.hash(surname, name, patronymic, birthday, gender,
                education, educationDocId, institute, dateOfEmployment,
                homeAddress);
    }

    @Override
    public String toString() {
        return "Surname: " + surname + ", Name: " + name + ", Patronymic: "
                + patronymic + "\nBirthday: " + birthday + ", Gender: " + gender
                + "\nEducation: " + education + ", Education document id: "
                + educationDocId + "\nInstitute: " + institute
                + "\nDate of employment: " + dateOfEmployment
                + "\nHome address: " + homeAddress;
    }
}
