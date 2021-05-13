/*-------------------------------------------------------------------<Header>-
 Name: ex_12.cpp
 Title: operator new example
 Description: Вопрос для размышления: в чем, по вашему мнению, при неудачной
 попытке выделения памяти преимущество возбуждения исключительной ситуации
 оператором new по сравнению с возвращением нуля?
 -------------------------------------------------------------------</Header>-*/

// Розглянемо приклад, де відбувається ДВА динамічних виділення пам'яті:
// зовнішнє (main) і всередині класу MyClass

#include <iostream>     // std::cout

class MyClass {
    int *data;
public:
    MyClass() {
        std::cout << "constructed [" << this << "]\n";
        data = new (std::nothrow) int[100000]();
        if (!data) {
            // Нехай тут відбудеться збій при виділенні пам'яті для data.
            // Без генерации исключительной ситуации сдесь не обойтись.
            // Исключения позволяют обрабатывать вложенные сбои так же, как и
            // внешние (раскручивание стека).
            // Это мощный механизм избежания дублирования кода и ошибок.
            std::cerr << " Allocation Error\n";
            exit(EXIT_FAILURE);
        }
    }
    ~MyClass() {
        delete[] data;
    }
};

int main () {
    std::cout << " 1: ";
    MyClass *p1 = new (std::nothrow) MyClass;
    if (!p1) {
        // ...
    }

    std::cout << " 2: ";
    MyClass *p2;
    try {
        p2 = new MyClass;
    }
    catch (std::bad_alloc &ba) {
        std::cerr << " bad_alloc caught: " << ba.what() << '\n';
    }

    // ...

    delete p1;
    delete p2;
    return 0;
}