/*
Задача 7.1. Для класса coord (См. Unit7 "Overloading An Operator In Which The Order Of
The Operands Is Important") перегрузите операторы * и /. Продемонстрируйте их работу.
*/

#include <iostream>

using namespace std;

class coord {
    int x, y;
public:
    coord();
    coord(int i, int j);
    ~coord();
    void get_xy(int &i, int &j) { i = x; j = y; }
    coord operator+(const coord &obj);
    coord operator*(const coord &obj);
    coord operator/(const coord &obj);
};

coord::coord() {
    x = 0;
    y = 0;
    cout << "Constructing A." << "\n"; 
}

coord::coord(int i, int j) {
    x = i;
    y = j;
    cout << "Constructing B." << "\n"; 
}

coord::~coord() {
    cout << "Destructing." << "\n";
}

coord coord::operator+(const coord &obj) {
    coord temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}

coord coord::operator*(const coord &obj) {
    coord temp;
    temp.x = x * obj.x;
    temp.y = y * obj.y;
    return temp;
}

coord coord::operator/(const coord &obj) {
    coord temp;
    temp.x = x / obj.x;
    temp.y = y / obj.y;
    return temp;
}

int main() {
    coord obj1(10, 30), obj2(5, 3), obj3;
    int x, y;

    obj3 = obj1 + obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 + obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 * obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 * obj2) X: " << x << ", Y: " << y << "\n";

    obj3 = obj1 / obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 / obj2) X: " << x << ", Y: " << y << "\n";
    
    return 0;
}