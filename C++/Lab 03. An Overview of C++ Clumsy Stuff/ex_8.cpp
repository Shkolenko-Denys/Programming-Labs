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
    int returntos();
};
stack::stack() {
    tos = 0;
}
void stack::push(char ch) {
    stck[tos] = ch;
    tos++;
}
char stack::pop() {
    if (tos == 0) {
        cout << "Empty!" << endl;
    }
    tos--;
    return stck[tos];
}
int stack::returntos() {
    return tos;
}
void showstack(stack s) {
    while (s.returntos() > 0) {
        cout << "Pop: " << s.pop() << endl;
    }
}

int main() {
    stack s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    showstack(s);
    return 0;
}