/* Задача 8.4. Исследуйте следующую конструкцию:
#include <iostream>
using namespace std;
class mybase {
    int a, b;
public:
    int c;
    void setab(int i, int j) { a = i; b = j; }
    void getab(int &i, int &j) { i = a; j = b; }
};
class derived1 : public mybase {
    // ...
};
class derived2 : private mybase {
    // ...
};
int main() {
    derived1 obj1;
    derived2 obj2;
    int i, j;
    // ...
}
Какая из следующих инструкций правильна внутри функции main() и почему?
A) obj1.getab(i, j);
B) obj2.getab(i, j);
C) obj1.c = 10;
D) obj2.c = 10; */

#include <iostream>

using namespace std;

class mybase {
private:
    int a, b;
public:
    int c;
    void setab(int i, int j) { a = i; b = j; }
    void getab(int &i, int &j) { i = a; j = b; }
};

class derived1 : public mybase {
    // Public inheritance:
    // public       ->    public
    // private      ->    not available
    // protected    ->    protected
};

class derived2 : private mybase {
    // Private inheritance:
    // public       ->    private
    // private      ->    not available
    // protected    ->    private
};

int main() {
    derived1 obj1; // public inheritance
    derived2 obj2; // private inheritance
    int i, j;

    // allowed: getab() is accessible from the outside through the child class
    obj1.getab(i, j);

    // forbidden: getab() is not accessible from the outside through the child class
    obj2.getab(i, j);

    // allowed: c is accessible from the outside through the child class
    obj1.c = 10;

    // forbidden: c is not accessible from the outside through the child class
    obj2.c = 10;
    return 0;
}