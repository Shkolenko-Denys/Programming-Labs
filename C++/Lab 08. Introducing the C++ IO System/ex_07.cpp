/*-------------------------------------------------------------------<Header>-
 Name: ex_07.cpp
 Title: —
 Description: Выполните еще раз Задачу 9.5 и 9.6, только теперь, вместо
 функций-членов и флагов формата, используйте манипуляторы ввода/вывода.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

void center(const string str) {
    int len = str.size();
    cout << setw(40 + (len / 2)) << str << "\n";
}

int main() {
    cout << fixed << setprecision(5);
    for (int i = 2; i <= 100; ++i) {
        cout << setw(10) << i << setw(10) << log(i) << setw(10) << log10(i) << "\n";
    }
    cout << "\n\n";

    center("Hello World!");

    cout << "\n\n";

     
    return 0;
}