/*-------------------------------------------------------------------<Header>-
 Name: ex_03.cpp
 Title: —
 Description: Напишите программу, которая бы устанавливала флаги для потока
 cout так, чтобы всегда при выводе дробных значений были показаны десятичные
 точки. Кроме этого, значения с плавающей точкой должны выводиться в научной
 нотации с символом "Е" в верхнем регистре.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

int main() {
    cout.setf(ios::showpoint | ios::scientific | ios::uppercase);
    cout << 30.23 << "\n";
    return 0;
}