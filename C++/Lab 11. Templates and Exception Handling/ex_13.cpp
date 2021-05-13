/*-------------------------------------------------------------------<Header>-
 Name: ex_13.cpp
 Title: —
 Description: В Unit 2 "Introducing Function Overloading" были созданы
 перегруженные версии функции abs(). Усовершенствуйте решение, создав родовую
 функцию abs(), которая возвращала бы абсолютную величину любого численного
 объекта.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

template <typename T>
T abs(const T &n) {
    return n < 0 ? -n : n;
}

int main() {
    std::cout << " Absolute value of -10: " << abs(-10) << "\n";
    std::cout << " Absolute value of -10L: " << abs(-10L) << "\n";
    std::cout << " Absolute value of -10.01: " << abs(-10.01) << "\n\n";
    return 0;
}