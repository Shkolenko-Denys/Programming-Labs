/*-------------------------------------------------------------------<Header>-
 Name: ex_11.cpp
 Title: —
 Description: Поскольку для конструктора с одним аргументом преобразование
 типа этого аргумента в тип класса, в котором определен конструктор, происходит
 автоматически, исчезает ли в этой ситуации необходимость в использовании
 перегруженного оператора присваивания? Ответ продемонстрируйте на примере.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class myclass {
    int a;
    int *arr;
public:
    myclass(const int &x) {
        a = x;
        arr = nullptr; // just example
        cout << "Construction...\n";
    }
    int geta() { return a; }
};

int main() {
    myclass obj1 = 5; // constructor called
    cout << "obj1: " << obj1.geta() << endl;

    obj1 = 55; // constructor called !!!
    cout << "obj1: " << obj1.geta() << endl;

    obj1 = 555; // constructor called !!!
    cout << "obj1: " << obj1.geta() << endl;
    return 0;
}