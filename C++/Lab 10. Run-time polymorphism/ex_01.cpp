/*-------------------------------------------------------------------<Header>-
 Name: ex_01.cpp
 Title: —
 Description: Создайте манипулятор для вывода чисел в научной нотации с
 символом Е в верхнем регистре.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

using namespace std;

ostream& up_scientific(ostream &stream) {
    stream.setf(ios::scientific | ios::uppercase);
    return stream;
}


int main() {
    cout << up_scientific << 555.55 << "\n\n";

    system("pause");
    return 0;
}