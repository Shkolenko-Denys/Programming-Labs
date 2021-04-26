/*-------------------------------------------------------------------<Header>-
 Name: ex_07_2.cpp
 Title: Example 11.5
 Description: В Example 11.5 попытайтесь удалить переопределение функции
 func() внутри класса derived2. Убедитесь, что тогда действительно будет
 использоваться та версия функции func(), переопределение которой находится в
 классе derived1. Что произойдет в Example 11.5 при удалении переопределения
 функции func() из класса derived1? Будет ли при этом программа
 компилироваться и запускаться? Если да, то почему?
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class base {
public:
    virtual void func() {
        cout << " Using base version of func()\n";
    }
};

class derived1 : public base {
public:
    // virtual void func() {
    //     cout << " Using derived1 version of func()\n";
    // }
};

// derived2 inherits derived1:
class derived2 : public derived1 {
public:
    // virtual void func() {
    //     cout << " Using derived2 version of func()\n";
    // }
};

int main() {
    base *p;
    base obj;

    derived1 objd1;
    derived2 objd2;

    p = &obj;
    p->func(); // use base func()
    p = &objd1;
    p->func(); // use derived1 func()
    p = &objd2;
    p->func(); // use derived2 func()
    return 0;
}

/*
When calling a method through an object of a child class,
the compiler first looks to see if that method exists in the child class.
If not, then it starts moving up the inheritance chain and checks if
this method was defined in any of the parent classes.
The compiler will use the first definition it finds.
*/