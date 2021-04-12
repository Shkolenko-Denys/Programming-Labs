/*
Задача 7.8. Перепишите класс coord так, чтобы можно было использовать объекты типа
coord для умножения каждой из координат на целое. Должны быть корректными обе
следующие инструкции: obj * int и int * obj. Объясните, почему решение требует
использования дружественных оператор-функций. Покажите, как с помощью
дружественной оператор-функции перегрузить оператор - относительно класса coord.
Определите как префиксную, так и постфиксную формы.
*/

// We can overload operator* (const coord &, int) via a class method.
// We cannot overload operator+ (int, const coord &) via a class method,
// since int is now the left operand that the *this pointer cannot point to.

// For example, coord(5, 3) + 5 will result in operator+ (coord, int) being called,
// and 5 + coord(5, 3) will result in operator+ (int, coord) being called.
// Therefore, whenever you overload binary operators to work with operands of different
// types, you need to write two functions - one for each case.

#include <iostream>

using namespace std;

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }
    friend coord operator *(const coord &obj, int i);
    friend coord operator *(int i, const coord &obj);

    friend coord operator-(coord &obj); // unary prefix minus
    friend coord operator-(const coord &obj1, const coord &obj2); // binary postfix minus
};

coord operator *(const coord &obj, int i){
    coord temp;
    temp.x = obj.x * i;
    temp.y = obj.y * i;
    return temp;
}

coord operator *(int i, const coord &obj){
    coord temp;
    temp.x = i * obj.x;
    temp.y = i * obj.y;
    return temp;
}

coord operator-(coord &obj) { // unary prefix minus
    obj.x = -obj.x;
    obj.y = -obj.y;
    return obj;
}

coord operator-(const coord &obj1, const coord &obj2) { // binary postfix minus
    coord temp;
    temp.x = obj1.x - obj2.x;
    temp.y = obj1.y - obj2.y;
    return temp;
}

int main() {
    coord obj1(10, 9), obj2;
    int x, y;

    obj2 = obj1 * 3;
    -obj2;
    obj2.get_xy(x, y);
    cout << "(obj1 * 3) X: " << x << ", Y: " << y << "\n";

    obj2 = 9 * obj1;
    obj2 = obj2 - obj1;
    obj2.get_xy(x, y);
    cout << "(9 * obj1) X: " << x << ", Y: " << y << "\n";

    return 0;
}