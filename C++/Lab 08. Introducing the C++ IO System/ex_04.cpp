/*-------------------------------------------------------------------<Header>-
 Name: ex_04.cpp
 Title: —
 Description: Напишите программу, которая сохраняет текущее состояние флагов
 формата, устанавливает флаги showbase и hex, выводит на экран значение 100,
 а затем возвращает флаги в исходное состояние.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

int main() {
    ios::fmtflags f;

    f = cout.flags(); // get flag
    cout.setf(ios::hex | ios::showbase, ios::basefield | ios::showbase);
    cout << 100 << "\n";

    cout.setf(f); // 1
    cout << 100 << "\n";

    cout.setf(ios::hex | ios::showbase, ios::basefield | ios::showbase);
    cout << 100 << "\n";

    cout.flags(f); // 2
    cout << 100 << "\n";
    return 0;
}