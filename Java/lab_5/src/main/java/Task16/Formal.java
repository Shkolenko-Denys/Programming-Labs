package Task16;

import Task16.Genders;

public interface Formal {

    String getSurname();
    void setSurname(String surname);

    String getName();
    void setName(String name);

    String getPatronymic();
    void setPatronymic(String patronymic);

    String getBirthday();
    void setBirthday(String birthday);

    Genders getGender();
    void setGender(Genders gender);

    String getHomeAddress();
    void setHomeAddress(String homeAddress);
}
