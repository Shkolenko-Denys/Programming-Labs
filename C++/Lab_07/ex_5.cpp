/* Задача 8.5. Если бы переменные а и b внутри класса myclass Задача 8.4 стали
не закрытыми (по умолчанию), а защищенными членами, изменился бы какой-нибудь
из ваших ответов на вопросы этого упражнения? Если да, то почему? */

// Nothing will change in this implementation. Because:
// public: this member is accessible to all objects
//
// private: this member is only accessible to other members of the Parent class
// and to friendly classes / functions (but not child classes)
//
// protected: access to this member is open to other members of the Parent class,
// friendly classes / functions, child classes

#include <iostream>

using namespace std;

class mybase {
protected:
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