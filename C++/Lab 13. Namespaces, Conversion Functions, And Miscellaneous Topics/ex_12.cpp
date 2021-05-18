/*-------------------------------------------------------------------<Header>-
 Name: ex_12.cpp
 Title: —
 Description: Можно ли в постоянной функции-члене использовать оператор
 const_cast, чтобы разрешить этой функции-члену модифицировать вызвавший ее
 объект? Ответ продемонстрируйте на примере.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class X {
    int data;
public:
    X(const int &d) : data(d) {}
    void set_data() const {
        const_cast<int &> (data) = 100;
    }
    int get_data() { return data; }
};

int main() {
    X obj(2);
    cout << "Num: " << obj.get_data() << "\n";
    obj.set_data();
    cout << "Num: " << obj.get_data() << "\n\n";
    return 0;
}