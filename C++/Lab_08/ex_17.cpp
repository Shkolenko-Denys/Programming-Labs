/*-------------------------------------------------------------------<Header>-
 Name: ex_17.cpp
 Title: —
 Description: Создайте для следующего класса пользовательские функции ввода и
 вывода:
 class pwr {
     int base;
     int exponent;
     double result; // base to the exponent power
 public:
     pwr(int b, int e);
 };
 pwr::pwr(int b, int e) {
     base = b;
     exponent = e;
     result = 1;
     for ( ; e; e--)
     result = result * base;
 }
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib> // system()

using namespace std;

int main() {

    system("pause");
    return 0;
}