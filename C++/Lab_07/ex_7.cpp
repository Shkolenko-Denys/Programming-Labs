/* Задача 8.7. Используя следующий фрагмент, создайте соответствующие конструкторы саr() и
truck(). Они должны передавать необходимые аргументы объектам класса vehicle. Кроме этого
конструктор саr() должен при создании объекта инициализировать переменную passengers, а
конструктор truck() - переменную loadlimit.
#include <iostream>
using namespace std;
// A base class for various types of vehicle:
class vehicle {
    int num_wheels;
    int range;
public:
    vehicle(int w, int r) {
        num_wheels = w;
        range = r;
    }
    void showv() {
        cout << "Wheels: " << num_wheels << '\n';
        cout << "Range: " << range << '\n';
    }
};
class car : public vehicle {
    int passengers;
public:
    void show() {
        showv();
        cout << "Passengers: " << passengers << '\n';
    }
};
class truck : public vehicle {
    int loadlimit;
public:
    void show() {
        showv();
        cout << "Loadlimit: " << loadlimit << '\n';
    }
};
int main() {
    car objc(5, 4, 500);
    truck objt(3000, 12, 1200);
    cout << "Car:\n";
    objc.show();
    cout << "Truck:\n";
    objt.show();
    return 0;
}
Для конструкторов саr() и truck() объекты должны объявляться следующим образом:
car obj(passengers, wheels, range);
truck obj(loadlimit, wheels, range); */

#include <iostream>

using namespace std;

// A base class for various types of vehicle:
class vehicle {
    int num_wheels;
    int range;
public:
    vehicle(int w, int r) {
        num_wheels = w;
        range = r;
    }
    void showv() {
        cout << "Wheels: " << num_wheels << '\n';
        cout << "Range: " << range << '\n';
    }
};

class car : public vehicle {
    int passengers;
public:
    car(int passengers, int wheels, int range) : vehicle(wheels, range) {
        this->passengers = passengers;
    }
    void show() {
        showv();
        cout << "Passengers: " << passengers << '\n';
    }
};

class truck : public vehicle {
    int loadlimit;
public:
    truck(int loadlimit, int wheels, int range) : vehicle(wheels, range) {
        this->loadlimit = loadlimit;
    }
    void show() {
        showv();
        cout << "Loadlimit: " << loadlimit << '\n';
    }
};

int main() {
    car objc(5, 4, 500);
    truck objt(3000, 12, 1200);
    cout << "Car:\n";
    objc.show();
    cout << "Truck:\n";
    objt.show();
    return 0;
}