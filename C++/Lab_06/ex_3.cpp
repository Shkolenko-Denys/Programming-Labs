/*
Задача 7.3. Поэкспериментируйте, меняя тип возвращаемого значения операторфункций на
что-нибудь отличное от coord. Обратите внимание на генерируемые
компилятором сообщения об ошибках. Объясните причины ошибок.
*/

#include <iostream>

using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }
    int operator+(const coord &obj);
};

int coord::operator+(const coord &obj) {
    coord temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}

int main() {
    coord obj1(10, 10), obj2(5, 3), obj3;
    int x, y;

    obj3 = obj1 + obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 + obj2) X: " << x << ", Y: " << y << "\n";
    
    return 0;
}
/*
 error: cannot convert 'coord' to 'int' in return
     return temp;
            ^~~~
*/

// Typically, overloaded operator functions return an object of the class
// with which they operate. Therefore, the overloaded operator can be used
// inside expressions. For example, if the operator function "operator + ()"
// returned an object of a different type, the following expression will be
// incorrect: "obj3 = obj1 + obj2;".
// To assign the sum of objects "obj1" and "obj2" to object "obj3",
// it is necessary that the result of the "+" operation be of the "coord" type.