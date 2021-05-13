/*-------------------------------------------------------------------<Header>-
 Name: ex_06.cpp
 Title: —
 Description: Создайте манипулятор ввода skipchar(), который поочередно то
 считывает, то пропускает каждые 5 символов потока ввода.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<char> v;

istream& skipchar(istream &in) {
    bool run = true;
    char ch;
    in.unsetf(ios::skipws);
    while (run) {
        for (int i = 0; i < 5 && run; ++i) {
            in >> ch;
            if (ch == '\n') { run = false; }
            v.push_back(ch);
        }
        for (int i = 0; i < 5 && run; ++i) {
            in >> ch;
            if (ch == '\n') { run = false; }
        }
    }
    return in;
}

int main() {
    cout << " Enter the text: ";
    cin >> skipchar;
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
    }
    cout << "\n\n";

     
    return 0;
}