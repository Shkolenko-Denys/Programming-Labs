/*-------------------------------------------------------------------<Header>-
 Name: ex_06.cpp
 Title: —
 Description: Создайте функцию center() со следующим прототипом:
 void center(char *s);
 Эта функция должна устанавливать заданную строку в центр экрана. Для реализации
 этой задачи воспользуйтесь функцией width(). Предполагается, что ширина экрана
 равна 80 символам. (Для простоты считайте, что длина строки не превышает 80
 символов.) Напишите программу, иллюстрирующую работу этой функции.
 Совет: Поэкспериментируйте с флагами и функциями формата. После того как вы
 ближе познакомитесь с системой ввода/вывода C++, вы, хочется верить, никогда
 не ошибетесь в выборе нужного формата вывода. :)
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// void center(const string str) {
//     int len = str.size();
//     cout.width(40 + (len / 2));
//     cout << str << "\n";
// }

// void center(const char *str) {
//     int len = strlen(str);
//     cout << setw(40 + (len / 2)) << str << "\n";
// }

void center(const char *str) {
    int len = strlen(str);
    cout.width(40 + (len / 2));
    cout << str << "\n";
}

int main() {
    center("Hello World!");

    system("pause");
    return 0;
}