/* Задача 8.8. Используя следующую иерархию классов, создайте конструктор класса
С так, чтобы он инициализировал переменную k и передавал аргументы конструкторам
А() и В().
#include <iostream>
using namespace std;
class A {
    int i;
public:
    A(int a) { i = a; }
};
class B {
    int j;
public:
    B(int a) { j = a; }
};
class C : public A, public B {
    int k;
public:
// Create C() so that it initializes k and passes arguments to both A() and B()
}; */

#include <iostream>

using namespace std;

class A {
    int i;
public:
    A(int a) { i = a; }
    int get() { return i;}
};

class B {
    int j;
public:
    B(int a) { j = a; }
    int get() { return j;}
};
class C : public A, public B {
    int k;
public:
    C(int a, int b, int c) : A(a), B(b), k(c)
    {
    }
    void show() {
        cout << A::get() << " " << B::get() << " " << k << "\n";
    }
};

int main() {
    C obj(1, 2, 3);
    obj.show();
    return 0;
}