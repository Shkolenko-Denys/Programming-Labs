/* Задача 8.9. Создайте исходный базовый класс building для хранения числа
этажей и комнат в здании, а также общую площадь комнат. Создайте производный
класс house, который наследует класс building и хранит число ванных комнат и
число спален. Кроме этого создайте производный класс office, который наследует
класс building и хранит число огнетушителей и телефонов. */

#include <iostream>

class Building
{
private:
    int n_floors;
    int n_rooms;
    int total_area;

public:
    Building(int n_floors = 0, int n_rooms = 0, int total_area = 0)
    : n_floors(n_floors), n_rooms(n_rooms), total_area(total_area)
    {
    }

    int get_n_floors() const { return n_floors; }
    int get_n_rooms() const { return n_rooms; }
    int get_total_area() const { return total_area; }
};

class House: public Building
{
private:
    int n_bathrooms;
    int n_bedrooms;

public:
    House(int n_floors = 0, int n_rooms = 0, int total_area = 0,
        int n_bathrooms = 0, int n_bedrooms = 0)
        : Building(n_floors, n_rooms, total_area),
        n_bathrooms(n_bathrooms), n_bedrooms(n_bedrooms)
    {
    }

    int get_n_bathrooms() const { return n_bathrooms; }
    int get_n_bedrooms() const { return n_bedrooms; }
};

class Office: public Building
{
private:
    int n_fire_extinguishers;
    int n_telephones;

public:
    Office(int n_floors = 0, int n_rooms = 0, int total_area = 0,
        int n_fire_extinguishers = 0, int n_telephones = 0)
        : Building(n_floors, n_rooms, total_area),
        n_fire_extinguishers(n_fire_extinguishers), n_telephones(n_telephones)
    {
    }

    int get_n_fire_extinguishers() const { return n_fire_extinguishers; }
    int get_n_telephones() const { return n_telephones; }
};

int main()
{
    House MyHouse(2, 6, 200, 2, 3);
    Office MyOffice(3, 10, 500, 5, 10);

    std::cout << "  MyHouse" << "\n";
    std::cout << "n_floors = " << MyHouse.get_n_floors() << "\n";
    std::cout << "n_rooms = " << MyHouse.get_n_rooms() << "\n";
    std::cout << "total_area = " << MyHouse.get_total_area() << "\n";
    std::cout << "n_bathrooms = " << MyHouse.get_n_bathrooms() << "\n";
    std::cout << "n_bedrooms = " << MyHouse.get_n_bedrooms() << "\n\n";

    std::cout << "  MyOffice" << "\n";
    std::cout << "n_floors = " << MyOffice.get_n_floors() << "\n";
    std::cout << "n_rooms = " << MyOffice.get_n_rooms() << "\n";
    std::cout << "total_area = " << MyOffice.get_total_area() << "\n";
    std::cout << "n_fire_extinguishers = " << MyOffice.get_n_fire_extinguishers() << "\n";
    std::cout << "n_telephones = " << MyOffice.get_n_telephones() << "\n\n";

    return 0;
}