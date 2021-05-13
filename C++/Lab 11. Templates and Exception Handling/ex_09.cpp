/*-------------------------------------------------------------------<Header>-
 Name: ex_09.cpp
 Title: —
 Description: Измените класс Stack так, чтобы в стеке можно было хранить
 пары объектов разных типов
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>

template <class StackType_1, class StackType_2, int size = 10>
class Stack {
    StackType_1 stck_1[size];
    StackType_2 stck_2[size];
    int len;
public:
    Stack() { len = 0; }
    void push(const StackType_1&, const StackType_2&);
    std::ostream& pop(std::ostream&);
};

int main() {
    Stack<char, int> s1;
    Stack<double, char> s2;
    s1.push('a', 1);
    s1.push('b', 2);
    s1.push('c', 3);
    s2.push(1.11, 'd');
    s2.push(2.22, 'e');
    s2.push(3.33, 'f');

    for (int i = 0; i < 3; ++i) {
        std::cout << " Pop s1: ";
        s1.pop(std::cout) << "\n";
    }
    std::cout << "\n";
    
    for (int i = 0; i < 3; ++i) {
        std::cout << " Pop s2: ";
        s2.pop(std::cout) << "\n";
    }
    std::cout << "\n";
    return 0;
}

template <class StackType_1, class StackType_2, int size>
void Stack<StackType_1, StackType_2, size>::push(const StackType_1 &obj_1, const StackType_2 &obj_2) {
    if (len == size) {
        std::cerr << " Stack Overflow\n";
        exit(EXIT_FAILURE);
    }
    stck_1[len] = obj_1;
    stck_2[len] = obj_2;
    len++;
}

template <class StackType_1, class StackType_2, int size>
std::ostream& Stack<StackType_1, StackType_2, size>::pop(std::ostream &out) {
    if (len == 0) {
        std::cerr << " Stack is empty\n";
        exit(EXIT_FAILURE);
    }
    len--;
    out << std::setw(5) << stck_1[len] << std::setw(5) << stck_2[len];
    return out;
}