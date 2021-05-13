/*-------------------------------------------------------------------<Header>-
 Name: ex_01.cpp
 Title: —
 Description: Напишите программу для вывода предложения: "I hate C++" в поле
 шириной 30 символов с использованием двоеточия (:) в качестве символа
 заполнения
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
    cout << setw(30) << setfill(':') << "I hate C++" << "\n\n";

     
    return 0;
}