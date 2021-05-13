/*-------------------------------------------------------------------<Header>-
 Name: ex_05.cpp
 Title: —
 Description: Разработайте программу для печати таблицы натуральных и десятичных
 логарифмов чисел от 2 до 100. Формат таблицы следующий: правое выравнивание,
 ширина поля — 10 символов, точность — 5 десятичных позиций.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(5);

    for (int i = 2; i <= 100; ++i) {
        cout << setw(10) << i << setw(10) << log(i) << setw(10) << log10(i) << "\n";
    }
    cout << "\n\n";

    return 0;
}