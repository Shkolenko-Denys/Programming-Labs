/*-------------------------------------------------------------------<Header>-
 Name: ex_17.cpp
 Title: —
 Description: Создайте манипулятор для вывода трех символов табуляции и
 установки ширины поля равной 20. Продемонстрируйте работу манипулятора.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

ostream& tabs(ostream &stream)
{
    stream << "\t\t\t" << setw(20);
    return stream;
}


int main()
{
    cout << tabs << "Hello World!" << "\n\n";
    // "Hello World" - the first words of a real programmer :)

     
    return 0;
}