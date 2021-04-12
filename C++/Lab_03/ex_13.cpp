#include <iostream>
using namespace std;

class stack {
    int tos;
    char stck[26];
public:
    stack();
    void push(char ch);
    char pop();
    void showstack();
    int sizestck() {
        return sizeof(stck) / sizeof(stck[0]);
    }
};
stack::stack() {
    tos = 0;
}

stack loadstack() {
    stack temp;
    for (char ch = 'a'; ch <= 'z'; ch++)
        temp.push(ch);
    cout << endl;
    return temp;
}
stack loadstack(int mode) {
    stack temp;
    if (temp.sizestck() < 26) {
        cout << "Error" << endl;
    } else {
        if (mode != 1) {
            temp = loadstack();
            return temp;
        }
        for (char ch = 'A'; ch <= 'Z'; ch++)
            temp.push(ch);
        cout << endl;
    }
    return temp;
}

void stack::showstack() {
    while(tos > 0) {
        cout << pop() << ' ';
    }
    cout << endl;
}
void stack::push(char ch) {
    stck[tos] = ch;
    tos++;
    stck[tos] = 0;
}
char stack::pop() {
    if (tos == 0)
        cout << "Empty!" << endl;
    tos--;
    return stck[tos];
}

int main() {
    stack s;
    s = loadstack();
    s.showstack();
    s = loadstack(1);
    s.showstack();
    return 0;
}