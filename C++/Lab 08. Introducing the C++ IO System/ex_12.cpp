/*-------------------------------------------------------------------<Header>-
 Name: ex_12.cpp
 Title: —
 Description: Создайте класс для хранения целого и его наименьшего делителя.
 Создайте для этого класса пользовательские функции ввода и вывода.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Int {
    int num;
    int least_div;
public:
    Int() { num = 0; least_div = 1; }
    Int(int num) : num(num) {
        least_div = 1;
    }
    friend ostream& operator<< (ostream &out, const Int &obj);
    friend istream& operator>> (istream &in, Int &obj);
};

ostream& operator<< (ostream &out, const Int &obj) {
    out << " Num = " << obj.num << " ; Least div = " << obj.least_div << "\n\n";
    return out;
}

istream& operator>> (istream &in, Int &obj) {
    in >> obj.num;
    return in;
}

int main() {
    Int number;
    cout << "Enter the number: ";
    cin >> number;
    cout << number;

     
    return 0;
}