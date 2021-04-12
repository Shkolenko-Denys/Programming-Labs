/*
Задача 7.4. Относительно класса coord (См. Unit7 "Overloading The Relational And Logical
Operators") перегрузите операторы отношения < и >.
*/

#include <iostream>

using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }
    // Since all comparison operators are binary and do not change
    // their left operands, overloading should be done through friendly functions.
    friend bool operator<(const coord &obj1, const coord &obj2);
    friend bool operator>(const coord &obj1, const coord &obj2);
};

bool operator<(const coord &obj1, const coord &obj2) {
    return (obj1.x < obj2.x && obj1.y < obj2.y);
}

bool operator>(const coord &obj1, const coord &obj2) {
    return (obj1.x > obj2.x && obj1.y > obj2.y);
}

int main() {
    coord obj1(10, 10), obj2(5, 3), obj3(50, 50);
    int x1, y1, x2, y2, x3, y3;

    obj1.get_xy(x1, y1);
    obj2.get_xy(x2, y2);
    obj3.get_xy(x3, y3);
    cout << "obj1 X: " << x1 << ", Y: " << y1 << "\n";
    cout << "obj2 X: " << x2 << ", Y: " << y2 << "\n";
    cout << "obj3 X: " << x3 << ", Y: " << y3 << "\n\n";

    if (obj1 < obj2) {
        cout << "obj1 < obj2" << "\n";
    } else {
        cout << "obj1 > obj2" << "\n";
    }
    if (obj2 < obj3) {
        cout << "obj2 < obj3" << "\n";
    } else {
        cout << "obj2 > obj3" << "\n";
    }
    if (obj1 < obj3) {
        cout << "obj1 < obj3" << "\n";
    } else {
        cout << "obj1 > obj3" << "\n";
    }
}