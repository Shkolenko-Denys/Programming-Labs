/*-------------------------------------------------------------------<Header>-
 Name: ex_02.cpp
 Title: —
 Description: Напишите программу, которая бы устанавливала флаги для потока
 cout так, чтобы целые, если они положительны, выводились со знаком +.
 Покажите, что ваш набор флагов формата правилен.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

int main() {
    std::cout.setf(std::ios::showpos);
    std::cout << 1 << "\n";
    std::cout << 2 << "\n";

    std::cout.unsetf(std::ios::showpos);
    std::cout << 3 << "\n";

    system("pause");
    return 0;
}