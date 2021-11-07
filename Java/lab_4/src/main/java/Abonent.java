public class Abonent {

    private String surname;
    private String name;
    private String patronymic;
    private String address;

    public Abonent(String surname, String name, String patronymic, String address) {
        this.setSurname(surname);
        this.setName(name);
        this.setPatronymic(patronymic);
        this.setAddress(address);
    }

    public void setSurname(String surname) throws IllegalArgumentException {
        if (surname.isEmpty()) {
            throw new IllegalArgumentException("surname cannot be empty");
        }
        this.surname = surname;
    }

    public String getSurname() {
        return surname;
    }

    public void setName(String name) throws IllegalArgumentException {
        if (name.isEmpty()) {
            throw new IllegalArgumentException("name cannot be empty");
        }
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setPatronymic(String patronymic) throws IllegalArgumentException {
        if (patronymic.isEmpty()) {
            throw new IllegalArgumentException("patronymic cannot be empty");
        }
        this.patronymic = patronymic;
    }

    public String getPatronymic() {
        return patronymic;
    }

    public void setAddress(String address) throws IllegalArgumentException {
        if (address.isEmpty()) {
            throw new IllegalArgumentException("address cannot be empty");
        }
        this.address = address;
    }

    public String getAddress() {
        return address;
    }

    @Override
    public String toString() {
        return surname + " " + name + " " + patronymic + " " + address;
    }
}
