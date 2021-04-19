#include <iostream>
using namespace std;
#define SIZE 10

class stack {
    char stck[SIZE];
    int tos;
public:
    stack();
    void push(char ch);
    char pop();
};
stack::stack() {
    tos = 0;
}

inline void stack::push(char ch) {
    stck[tos] = ch;
    tos++;
}
inline char stack::pop() {
    if (tos == 0)
        cout << "Stack is empty!" << endl;
    tos--;
    return stck[tos];
}

int main() {
    stack s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    for (int i = 0; i < 5; i++) {
        cout << "Pop: " << s.pop() << endl;
    }
    return 0;
}