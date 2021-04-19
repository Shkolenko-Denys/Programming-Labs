/*
Задача 7.5. Перегрузите оператор минус - относительно класса coord. Создайте его
префиксную и постфиксную формы.
*/

#include <iostream>

using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }
    coord operator-(); // unary prefix minus
    friend coord operator-(const coord &obj1, const coord &obj2); // binary postfix minus
};

coord coord::operator-() { // unary prefix minus
    x = -x;
    y = -y;
    return *this;
}

coord operator-(const coord &obj1, const coord &obj2) { // binary postfix minus
    coord temp;
    temp.x = obj1.x - obj2.x;
    temp.y = obj1.y - obj2.y;
    return temp;
}

int main() {
    coord obj1(10, 10), obj2(5, 3), obj3;
    int x, y;

    obj1.get_xy(x, y);
    cout << "obj1 X: " << x << ", Y: " << y << "\n";
    obj2.get_xy(x, y);
    cout << "obj2 X: " << x << ", Y: " << y << "\n\n";

    -obj1;
    -obj2;

    obj1.get_xy(x, y);
    cout << "obj1 X: " << x << ", Y: " << y << "\n";
    obj2.get_xy(x, y);
    cout << "obj2 X: " << x << ", Y: " << y << "\n\n";

    obj3 = obj1 - obj2;
    obj3.get_xy(x, y);

    cout << "obj3 X: " << x << ", Y: " << y << "\n\n";
    return 0;
}
    