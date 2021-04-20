#include <iostream>
using namespace std;

class stack {
    int tos;
    char *stck;
public:
    stack(int size);
    ~stack();
    void push(char ch);
    char pop();
};

stack::stack(int size) {
    tos = 0;
    stck = new char[size];
}

stack::~stack () {
    delete[] stck;
}

void stack::push (char ch) {
    stck[tos] = ch;
    tos++;
}

char stack::pop () {
    if (tos == 0)
        cout << "Empty!" << endl;
    tos--;
    return stck[tos];
}

int main () {
    stack s(50);
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    s.push('f');
    for (int i = 0; i < 6; i++) {
        cout << "Pop: " << s.pop() << endl;
    }
    return 0;
}