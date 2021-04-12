/*
Задача 7.2. В приведенном ниже примере некорректно перегружен оператор %. Почему?
coord coord::operator%(const coord obj) {
    double i;
    cout << "Enter a number: ";
    cin >> i;
    cout << "root of " << i << " is ";
    cout << sqrt(i);
}
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
    coord operator%(const coord &obj);
};

// coord coord::operator%(const coord obj) {
//     // Rule: When overloading operators, you should preserve the functionality
//     // of the operators as closely as possible in accordance with their original
//     // applications.
//     double i;
//     cout << "Enter a number: ";
//     cin >> i;
//     cout << "root of " << i << " is ";
//     cout << sqrt(i);
//     // need to return some variable of type coord !!!
// }

coord coord::operator%(const coord &obj) {
    coord temp;
    temp.x = x % obj.x;
    temp.y = y % obj.y;
    return temp;
}

// ERROR !!!
// coord coord::operator%(int) {
//     // the initial number of operands supported by the operator cannot be changed.
//     // That is, only two operands are used with a binary operator, only one with a unary,
//     // and only three with a ternary. 
//     coord temp;
//     temp.x = sqrt(x);
//     temp.y = sqrt(y);
//     return temp;
// }

int main() {
    coord obj1(10, 10), obj2(3, 5), obj3;
    int x, y;

    obj3 = obj1 % obj2;
    obj3.get_xy(x, y);
    cout << "(obj1 %% obj2) X: " << x << ", Y: " << y << "\n";

    // obj3 = obj2%; // ERROR !!!
    // obj3.get_xy(x, y);
    // cout << "(obj2%%) X: " << x << ", Y: " << y << "\n";

    return 0;
}