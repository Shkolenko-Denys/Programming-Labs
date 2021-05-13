/*-------------------------------------------------------------------<Header>-
 Name: ex_13.cpp
 Title: —
 Description: Напишите программу для вывода числа 100 в десятичной,
 шестнадцатеричной и восьмеричной системе счисления.
 (Используйте флаги формата класса ios.)
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

int main() {
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << " hex: " << 100 << "\n";

    std::cout.setf(std::ios::oct, std::ios::basefield);
    std::cout << " oct: " << 100 << "\n";
    
    std::cout.setf(std::ios::dec, std::ios::basefield);
    std::cout << " dec: " << 100 << "\n\n";
    
     
    return 0;
}