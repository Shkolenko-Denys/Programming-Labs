/*-------------------------------------------------------------------<Header>-
 Name: ex_05.cpp
 Title: —
 Description: Допишите следующую программу, чтобы на экран выводилась
 информация о выбранном пользователем типе объекта.
 #include <iostream>
 #include <typeinfo>
 using namespace std;
 class A {
    virtual void f() {}
 };
 class B: public A {};
 int main() {
    A *p, obja;
    B objb;
    C objc;
    int i;
    cout << "Enter 0 for A objects, ";
    cout << "1 for B objects or ";
    cout << "2 for C objects.\n";
    cin >> i;
    if (i==1)
        p = &Objb;
    else if (i==2)
        p = &objc;
    else
        p = &obja;
    // report type of object selected by user
    return 0;
 }
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <typeinfo>

using namespace std;

class A {
    virtual void f() {}
};

class B: public A {};
class C: public A {};

int main() {
    A *p, obja;
    B objb;
    C objc;
    int i;
    cout << "Enter 0 for A objects, ";
    cout << "1 for B objects or ";
    cout << "2 for C objects.\n";
    cin >> i;
    if (i == 1) {
        p = &objb;
    }
    else if (i == 2) {
        p = &objc;
    }
    else {
        p = &obja;
    }
    cout << " user-selected object: " << typeid(*p).name() << "\n";
    // The data provided by typeid - implementation defined
    // Specifically, g++ uses name mangling for naming types.
    // VS prints the type names as they are.

    // if (typeid(*p) == typeid(obja)) {
    //     cout << " user-selected object: A\n";
    // }
    // else if (typeid(*p) == typeid(objb)) {
    //     cout << " user-selected object: B\n";
    // }
    // else if (typeid(*p) == typeid(objc)) {
    //     cout << " user-selected object: C\n";
    // }
    return 0;
}