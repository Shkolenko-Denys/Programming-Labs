package Task16;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Objects;

/**
 * Class that describes Employee and extends Human
 *
 * @author Shkolenko
 * @version 1.0
 */
public class Employee extends Human {

    /** Education level */
    private EducationLevels education;

    /** Education document id */
    private int educationDocId;

    /** Institute */
    private String institute;

    /** Date of employment */
    private final String dateOfEmployment;

    /**
     * @param surname Employee's surname
     * @param name Employee's name
     * @param patronymic Employee's patronymic
     * @param birthday Employee's birthday
     * @param gender Employee's gender
     * @param homeAddress Employee's homeAddress
     * @param education Employee's education
     * @param educationDocId Employee's education document id
     * @param institute Employee's institute
     */
    public Employee(String surname, String name, String patronymic,
                    String birthday, Genders gender, String homeAddress,
                    EducationLevels education, int educationDocId,
                    String institute) {
        super(surname, name, patronymic, birthday, gender, homeAddress);
        setEducation(education);
        setEducationDocId(educationDocId);
        setInstitute(institute);
        this.dateOfEmployment = LocalDateTime.now().format(DateTimeFormatter
                .ofPattern("dd.MM.yyyy"));
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

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        Employee employee = (Employee) o;
        return educationDocId == employee.educationDocId
                && dateOfEmployment.equals(employee.dateOfEmployment);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), educationDocId, dateOfEmployment);
    }

    @Override
    public String toString() {
        return super.toString()
                + "\nEducation:" + education
                + "\nEducation document id: " + educationDocId
                + "\nInstitute: " + institute
                + "\nDate of employment: " + dateOfEmployment;
    }
}
