/*-------------------------------------------------------------------<Header>-
 Name: ex_05.cpp
 Title: —
 Description: Создайте свой манипулятор вывода sethex(), который осуществляет
 вывод в шестнадцатиричной системе счисления и устанавливает флаги uppercase
 и showbase. Кроме того, создайте манипулятор вывода reset(), который отменяет
 изменения, сделанные манипулятором sethex().
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

using namespace std;

void showflags();
ostream& sethex(ostream &stream);
ostream& reset(ostream &stream);

int main() {
    // showflags();
    cout << sethex << 100 << "\n\n";
    // showflags();
    cout << reset << 100 << "\n\n";
    // showflags();

     
    return 0;
}

ostream& sethex(ostream &stream) {
    stream.setf(ios::hex, ios::basefield);
    stream.setf(ios::uppercase | ios::showbase);
    return stream;
}

ostream& reset(ostream &stream) {
    stream.unsetf(ios::hex | ios::uppercase | ios::showbase);
    stream.setf(ios::dec);
    return stream;
}

void showflags() {
    ios::fmtflags f;
    f = cout.flags(); // get flag
    if (f & ios::dec) cout << "dec on\n";
    else cout << "dec off\n";
    if (f & ios::oct) cout << "oct on\n";
    else cout << "oct off\n";
    if (f & ios::hex ) cout << "hex on\n";
    else cout << "hex off\n";
    cout << "\n";
}