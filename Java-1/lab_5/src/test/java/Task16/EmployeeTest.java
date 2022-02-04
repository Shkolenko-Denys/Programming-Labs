package Task16;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class EmployeeTest {

    @Test
    void setEducationDocId() {
        Exception exception = assertThrows(IllegalArgumentException.class, () ->
                new Employee("surname", "name", "patronymic",
                "19.07.2003", Genders.MAN, "Kyiv",
                EducationLevels.BACHELOR, -23, "KPI"));

        String expectedMessage = "invalid document id";
        String actualMessage = exception.getMessage();

        assertTrue(actualMessage.contains(expectedMessage));
    }

    @Test
    void setInstitute() {
        Exception exception = assertThrows(IllegalArgumentException.class, () ->
                new Employee("surname", "name", "patronymic",
                "19.07.2003", Genders.MAN, "Kyiv",
                EducationLevels.BACHELOR, 23, ""));

        String expectedMessage = "the institute cannot be empty";
        String actualMessage = exception.getMessage();

        assertTrue(actualMessage.contains(expectedMessage));
    }
}