/*-------------------------------------------------------------------<Header>-
 Name: ex_05.cpp
 Title: —
 Description: Одним из интересных применений статических переменных-членов
 является хранение информации о количестве объектов класса, существующих в
 каждый конкретный момент времени. Для этого необходимо увеличивать на единицу
 статическую переменнуючлен каждый раз, когда вызывается конструктор класса,
 и уменьшать на единицу, когда вызывается деструктор. Реализуйте эту схему и
 продемонстрируйте ее работу.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class Example {
    static int s_count;
    const int data;
public:
    Example(const int &d) : data(d) {
        s_count++;
    }
    ~Example() {
        s_count--;
    }
    int get_count() { return s_count; }
};

int Example::s_count = 0;

int main() {
    Example obj1(12), obj2(2);
    cout << "Count " << obj1.get_count() << "\n";

    Example *new_obj = new Example(13);
    cout << "Count " << obj1.get_count() << "\n";
    
    delete new_obj;
    cout << "Count " << obj1.get_count() << "\n";
    return 0;
}