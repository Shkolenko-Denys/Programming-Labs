/*-------------------------------------------------------------------<Header>-
 Name: ex_02.cpp
 Title: —
 Description: Переделайте функцию main() из Example 13.6 так, чтобы для
 запрещения вывода на экран объектов типа NullShape использовался не оператор
 typeid, а оператор dynamic_cast
 -------------------------------------------------------------------</Header>-*/

#include <iostream>     // std::cout
#include <cstdlib>      // rand
#include <typeinfo>     // typeid

class Shape {
public:
    virtual void example() = 0;
};

class Rectangle : public Shape {
public:
    void example() {
        std::cout << "*****\n*   *\n*   *\n*****\n";
    }
};

class Triangle : public Shape {
public:
    void example() {
        std::cout << "*\n* *\n*  *\n*****\n";
    }
};

class Line : public Shape {
public:
    void example() {
        std::cout << "*****\n";
    }
};

class NullShape : public Shape {
public:
    void example() {
        std::cout << "Null !!! \n";
    }
};

// A factory for objects derived from Shape:
Shape *generator() {
    switch (rand() % 4) {
        case 0: return new Line;
        case 1: return new Rectangle;
        case 2: return new Triangle;
        case 3: return new NullShape;
    }
    return nullptr;
}

int main() {
    Shape *p;
    for (int i = 0; i < 10; i++) {
        p = generator(); // get next object
        std::cout << " class " << typeid(*p).name() << std::endl;
        // draw object only if it is not a NullShape
        if (!dynamic_cast <NullShape *> (p)) {
            p->example();
        }
    }
    return 0;
}