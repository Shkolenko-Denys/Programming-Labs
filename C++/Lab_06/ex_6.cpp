/*
Задача 7.6. Перегрузите оператор + относительно класса coord так, чтобы он был как
бинарным, так и унарным оператором (См. Unit7 "Overloading A Unary Operator"). При
использовании в качестве унарного оператор + должен делать положительным
значение любой отрицательной координаты.
*/

#include <iostream>
#include <cmath>

using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }
    coord operator+();
    coord operator+(const coord &obj);
};

coord coord::operator+() {
    x = abs(x);
    y = abs(y);
    return *this;
}

coord coord::operator+(const coord &obj) {
    coord temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}

int main() {
    coord obj1(-10, -10), obj2(-5, -3), obj3;
    int x, y;
    obj3 = obj1 + obj2;

    obj1.get_xy(x, y);
    cout << "obj1 X: " << x << ", Y: " << y << "\n";
    obj2.get_xy(x, y);
    cout << "obj2 X: " << x << ", Y: " << y << "\n";
    obj3.get_xy(x, y);
    cout << "obj3 X: " << x << ", Y: " << y << "\n\n";

    +obj3;
    obj3.get_xy(x, y);

    cout << "obj3 X: " << x << ", Y: " << y << "\n\n";
    return 0;
}