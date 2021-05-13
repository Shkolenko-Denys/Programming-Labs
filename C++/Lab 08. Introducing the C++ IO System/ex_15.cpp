/*-------------------------------------------------------------------<Header>-
 Name: ex_15.cpp
 Title: —
 Description: Перепишите ваши ответы на Задачи 9.13 и 9.14 так, чтобы
 использовались манипуляторы ввода/вывода.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

int main() {
    std::cout << std::hex << " hex: " << 100 << "\n";
    std::cout << std::oct << " oct: " << 100 << "\n";
    std::cout << std::dec << " dec: " << 100 << "\n\n";

    std::cout << std::setw(20) <<
    std::setprecision(6) <<
    std::setfill('*') <<
    std::left << 1000.5364 << "\n\n";

     
    return 0;
}