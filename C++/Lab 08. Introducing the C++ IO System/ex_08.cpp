/*-------------------------------------------------------------------<Header>-
 Name: ex_08.cpp
 Title: —
 Description: Составьте инструкцию для вывода числа 100 в шестнадцатеричной
 системе счисления с отображением основания системы счисления (0x).
 Для выполнения задания воспользуйтесь манипулятором setiosflags().
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

int main() {
    std::cout << std::hex;
    std::cout << std::setiosflags(std::ios::showbase);
    std::cout << 100 << std::endl;

     
    return 0;
}