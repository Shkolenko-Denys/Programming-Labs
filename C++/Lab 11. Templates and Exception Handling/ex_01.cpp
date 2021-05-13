/*-------------------------------------------------------------------<Header>-
 Name: ex_01.cpp
 Title: —
 Description: Напишите родовую функцию min(), возвращающую меньший из двух
 своих аргументов. Например, версия функции min(3, 4) должна возвратить 3,
 а версия min('c', 'a') - а. Продемонстрируйте работу функции с помощью
 программы.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

template <typename T>
const T& min(const T &a, const T &b) {
    return (a < b) ? a : b;
}

int main() {
    int i = min(3, 4);
    std::cout << i << "\n";
 
    double d = min(3.33, 4.44);
    std::cout << d << "\n";
 
    char ch = min('c', 'a');
    std::cout << ch << "\n\n";
    return 0;
}