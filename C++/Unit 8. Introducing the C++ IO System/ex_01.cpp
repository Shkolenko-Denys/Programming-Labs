/*-------------------------------------------------------------------<Header>-
 Name: ex_01.cpp
 Title: —
 Description: Создайте иерархию классов для хранения информации о летательных
 аппаратах. Начните с общего базового класса Airship, предназначенного для
 хранения количества перевозимых пассажиров и количества перевозимого груза в
 фунтах или килограммах, или тоннах. Затем создайте два производных от Airship
 класса Airplane и Balloon (дирижабль). Класс Airplane должен хранить тип
 самолетного двигателя (винтовой или реактивный) и дальность полета в милях или
 километрах. Класс Balloon должен хранить информацию о типе газа, используемого
 для подъема дирижабля (водород или гелий), и его максимальный потолок (в футах
 или метрах). Создайте программу для демонстрации работы этой иерархии классов.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

#define KILOGRAMS_PER_POUND 0.453592
#define KILOGRAMS_PER_TONNE 1000
#define KILOMETERS_PER_MILE 1.60934
#define FEET_PER_METER 3.28084

enum Engine {screw, reactive};
enum Gas {hydrogen, helium};

using namespace std;

class Airship
{
private:
    int n_passengers;
    double lb_load;
    double kg_load, ton_load;

public:
    Airship(int n_passengers = 0, double lb_load = 0)
    : n_passengers(n_passengers), lb_load(lb_load)
    {
        kg_load = lb_load * KILOGRAMS_PER_POUND;
        ton_load = kg_load / KILOGRAMS_PER_TONNE;
    }

    int get_n_passengers() const { return n_passengers; }
    double get_lb_load() const { return lb_load; }
    double get_kg_load() const { return kg_load; }
    double get_ton_load() const { return ton_load; }
};

class Airplane: public Airship
{
private:
    Engine engine;
    double miles_range, km_range;

public:
    Airplane(int n_passengers = 0, double lb_load = 0, Engine engine = screw,
        double miles_range = 0)
    : Airship(n_passengers, lb_load), engine(engine), miles_range(miles_range) 
    {
        km_range = miles_range * KILOMETERS_PER_MILE;
    }

    string get_engine() const {
        switch (engine) {
            case screw:
                return "screw";
            case reactive:
                return "reactive";
            default:
                return "screw";
        }
    }
    double get_miles_range() const { return miles_range; }
    double get_km_range() const { return km_range; }
};

class Balloon: public Airship
{
private:
    Gas gas;
    double ft_h, meters_h;

public:
    Balloon(int n_passengers = 0, double lb_load = 0, Gas gas = hydrogen,
        double ft_h = 0)
    : Airship(n_passengers, lb_load), gas(gas), ft_h(ft_h)
    {
        meters_h = ft_h / FEET_PER_METER;
    }

    string get_gas() const {
        switch (gas) {
            case hydrogen:
                return "hydrogen";
            case helium:
                return "helium";
            default:
                return "hydrogen";
        }
    }
    double get_ft_h() const { return ft_h; }
    double get_meters_h() const { return meters_h; }
};

int main()
{
    Airplane MyAirplane(1000, 100, screw, 5000);
    Balloon MyBalloon(900, 50, helium, 10000);

    std::cout << "  MyAirplane" << "\n";
    std::cout << "n_passengers = " << MyAirplane.get_n_passengers() << "\n";
    std::cout << "lb_load = " << MyAirplane.get_lb_load() << "\n";
    std::cout << "kg_load = " << MyAirplane.get_kg_load() << "\n";
    std::cout << "ton_load = " << MyAirplane.get_ton_load() << "\n";
    std::cout << "engine = " << MyAirplane.get_engine() << "\n";
    std::cout << "miles_range = " << MyAirplane.get_miles_range() << "\n";
    std::cout << "km_range = " << MyAirplane.get_km_range() << "\n\n";

    std::cout << "  MyBalloon" << "\n";
    std::cout << "n_passengers = " << MyBalloon.get_n_passengers() << "\n";
    std::cout << "lb_load = " << MyBalloon.get_lb_load() << "\n";
    std::cout << "kg_load = " << MyBalloon.get_kg_load() << "\n";
    std::cout << "ton_load = " << MyBalloon.get_ton_load() << "\n";
    std::cout << "gas = " << MyBalloon.get_gas() << "\n";
    std::cout << "ft_h = " << MyBalloon.get_ft_h() << "\n";
    std::cout << "meters_h = " << MyBalloon.get_meters_h() << "\n";

    return 0;
}