/*-------------------------------------------------------------------<Header>-
 Name: ex_07_1.cpp
 Title: Example 11.4 (Create an abstract class)
 Description: Проведите эксперимент с двумя программами из Example 11.4 и
 Example 11.5. Попытайтесь создать объект, используя класс area из Example 11.4,
 и проанализируйте сообщение об ошибке.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class area {
    double dim1, dim2; // dimensions of figure
public:
    void setarea(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
    }
    void getdim(double &d1, double &d2) {
        d1 = dim1;
        d2 = dim2;
    }
    virtual double getarea() = 0; // pure virtual function
};

class rectangle: public area {
public:
    double getarea() {
        double d1, d2;
        getdim(d1, d2);
        return d1 * d2;
    }
};

class triangle: public area {
public:
    double getarea() {
        double d1, d2;
        getdim(d1, d2);
        return 0.5 * d1 * d2;
    }
};

int main() {
    area obj; // Error !!!
    area *p;
    rectangle r;
    triangle t;
    r.setarea(3.3, 4.5);
    t.setarea(4.0, 5.0);
    p = &r;
    cout << " Rectangle has area: " << p->getarea() << '\n';
    p = &t;
    cout << " Triangle has area: " << p->getarea() << '\n';
    return 0;
}

/*
Any class with one or more pure virtual functions becomes an abstract class,
objects of which cannot be created!

Since we did not define the getarea() method,
what is the result of executing area.getarea() ?!
*/