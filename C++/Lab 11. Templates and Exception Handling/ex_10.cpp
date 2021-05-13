/*-------------------------------------------------------------------<Header>-
 Name: ex_10.cpp
 Title: —
 Description: Еще раз измените класс Stack так, чтобы переполнение и, наоборот,
 опустошение стека обрабатывались как исключительные ситуации.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

template <class StackType = int, int size = 3>
class Stack {
    StackType stck[size];
    int len;
public:
    Stack() { len = 0; }
    void push(const StackType &obj);
    StackType pop();
};

int main() {
    Stack<char> s1;
    Stack<> s2;

    try {
        s1.push('a');
        s1.push('b');
        s1.push('c');
        s2.push(111);
        s2.push(222);
        s2.push(333);
        s2.push(444);
    } catch (const char *exception) {
        std::cerr << " Error: " << exception << "\n\n";
    }

    for (int i = 0; i <= 3; ++i) {
        try {
            std::cout << " Pop s1: " << s1.pop() << "\n";
        }
        catch (const char *exception) {
            std::cerr << " Error: " << exception << "\n\n";
        }
    }

    for (int i = 0; i <= 3; ++i) {
        try {
            std::cout << " Pop s2: " << s2.pop() << "\n";
        }
        catch (const char *exception) {
            std::cerr << " Error: " << exception << "\n\n";
        }
    }
    return 0;
}

template <class StackType, int size>
void Stack<StackType, size>::push(const StackType &obj) {
    if (len == size) {
        throw "Stack Overflow";
    }
    stck[len] = obj;
    len++;
}

template <class StackType, int size>
StackType Stack<StackType, size>::pop() {
    if (len == 0) {
        throw "Stack is empty";
    }
    len--;
    return stck[len];
}