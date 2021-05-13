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
#include <cstdlib>

using namespace std;

class pwr {
    int base;
    int exponent;
    double result; // base to the exponent power
public:
    pwr(int b = 0, int e = 0);
    friend ostream& operator<< (ostream &out, const pwr &obj);
    friend istream& operator>> (istream &in, pwr &obj);
};

pwr::pwr(int b, int e) {
    base = b;
    exponent = e;
    result = 1;
    for ( ; e; e--) {
        result = result * base;
    }
}

ostream& operator<< (ostream &out, const pwr &obj) {
    out << " base = " << obj.base <<
    " ; exponent = " << obj.exponent <<
    " ; result = " << obj.result << "\n\n";
    return out;
}

istream& operator>> (istream &in, pwr &obj) {
    in >> obj.base >> obj.exponent;
    for (int e = obj.exponent; e; e--) {
        obj.result = obj.result * obj.base;
    }
    return in;
}

int main() {
    pwr obj;
    cout << "Enter base /space/ exponent : " << "\n";
    cin >> obj;
    cout << obj;

     
    return 0;
}