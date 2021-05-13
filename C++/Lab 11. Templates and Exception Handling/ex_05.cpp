/*-------------------------------------------------------------------<Header>-
 Name: ex_05.cpp
 Title: —
 Description: Здесь представлен каркас функции divide():
 double divide (double a, double b) {
    // add error handling
    return a/b;
 }
 Эта функция возвращает результат деления а на b. Добавьте в функцию код для
 обработки исключительных ситуаций, а конкретно предусмотрите обработку ошибки
 деления на ноль. Покажите, что ваша программа работает.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

double divide(const double &a, const double &b) {
    try {
        if (!b) {
            throw "Divide by zero!";
        }
        return a / b;
    }
    catch (const char *exception) {
        cerr << " Error: " << exception << '\n';
    }
    return 0;
}

int main() {
    cout << " Result_1 : " << divide(5.5, 0) << "\n";
    cout << " Result_2 : " << divide(5.5, 2) << "\n\n";
    return 0;
}