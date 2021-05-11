/*-------------------------------------------------------------------<Header>-
 Name: ex_06.cpp
 Title: —
 Description: a) Переделайте программу Example 13.3a, чтобы возможную ошибку
 выделения памяти внутри функции generator() отслеживать с помощью механизма
 обработки исключительных ситуаций.
 б) Измените функцию generator() из вопроса а), чтобы в ней использовать версию
 оператора new с ключевым словом nothrow.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <typeinfo>
#include <cmath>
#include <cstdlib>

using namespace std;

template <class T> class Num {
public:
    T x;
    Num(T i) { x = i; }
    virtual T get_val() { return x; }
};

template <class T> class Square : public Num <T> {
public:
    Square(T i) : Num<T>(i) {}
    T get_val() { return this->x * this->x; }
};

template <class T> class Sqr_root : public Num <T> {
public:
    Sqr_root(T i) : Num<T>(i) {}
    T get_val() { return sqrt((double)this->x); }
};

// A factory for objects derived from Num:
Num <double> *generator() {
    switch (rand() % 2) {
        case 0: return new (nothrow) Square<double> (rand() % 100);
        case 1: return new (nothrow) Sqr_root<double> (rand() % 100);
    }
    return nullptr;
}
int main() {
    Num<double> ob1(10), *p1;
    Square<double> ob2(100.0);
    Sqr_root<double> ob3(999.2);
    cout << typeid(ob1).name() << endl;
    cout << typeid(ob2).name() << endl;
    cout << typeid(ob3).name() << endl;

    if (typeid(ob2) == typeid(Square<double>)) {
        cout << "is Square <double>\n";
    }

    p1 = &ob2;
    if (typeid(*p1) != typeid(ob1)) {
        cout << "Value is: " << p1->get_val() << "\n\n";
    }
    cout << "Now, generate some Objects.\n";

    for (int i = 0; i < 10; i++) {
        // try {
            p1 = generator();
        // } catch (bad_alloc &ba) {
        //     cerr << "bad_alloc caught: " << ba.what() << '\n';
        //     break;
        // }
        if (!p1) {
            cout << "Failed!\n";
        } else {
            if (typeid(*p1) == typeid(Square<double>)) {
                cout << " Square object: ";
            }

            if (typeid(*p1) == typeid(Sqr_root<double>)) {
                cout << " Sqr_root object: ";
            }
            cout << "value is: " << p1->get_val() << endl;
        }
    } 
    return 0;
}