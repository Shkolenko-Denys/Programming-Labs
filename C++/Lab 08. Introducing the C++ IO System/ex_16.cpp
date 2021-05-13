/*-------------------------------------------------------------------<Header>-
 Name: ex_16.cpp
 Title: —
 Description: Покажите, как записать и как отобразить для класса cout флаги
 формата. Используйте функции-члены либо манипуляторы.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

using namespace std;

void showflags();

int main() {
    showflags();

    cout.setf(ios::oct, ios::basefield);
    showflags();

    cout << hex << 100 << "\n";
    showflags();

    cout << 200 << "\n";
    showflags();
    
    cout << dec << 300 << "\n";
    showflags();

     
    return 0;
}

void showflags() {
    ios::fmtflags f;
    f = cout.flags(); // get flag
    if (f & ios::dec)
        cout << "dec on\n";
    else
        cout << "dec off\n";
    if (f & ios::oct)
        cout << "oct on\n";
    else
        cout << "oct off\n";
    if (f & ios::hex )
        cout << "hex on\n";
    else
        cout << "hex off\n";
    cout << "\n";
}