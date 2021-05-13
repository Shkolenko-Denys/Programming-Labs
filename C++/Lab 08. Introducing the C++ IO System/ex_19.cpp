/*-------------------------------------------------------------------<Header>-
 Name: ex_19.cpp
 Title: —
 Description: Используя показанный здесь класс stack, создайте
 пользовательскую функцию вывода для вставки в поток содержимого стека.
 Покажите, что функция работает.
 #include <iostream>
 using namespace std;
 #define SIZE 10
 class stack {
     char stck[SIZE]; // holds the stack
     int tos; // index of top-of-stack
 public:
     stack();
     void push(char ch); // push character on stack
     char pop(); // pop character from stack
 };
 // Initialize the stack:
 stack::stack() {
     tos = 0;
 }
 // Push a character
 void stack::push (char ch) {
     if (tos == SIZE) {
         cout << "Stack is full\n";
         return 0;
     }
     stck[tos] = ch;
     tos++;
 }
 // Pop a character:
 char stack::pop() {
     if (tos==0) {
         cout << "Stack is empty\n";
         return 0;
     }
     tos--;
     return stck[tos];
 }
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

#define SIZE 10

using namespace std;

class stack {
    char stck[SIZE]; // holds the stack
    int tos; // index of top-of-stack
public:
    stack();
    int push(char ch); // push character on stack
    char pop(); // pop character from stack

    friend ostream& operator<< (ostream &out, stack &obj);
};

// Initialize the stack:
stack::stack() {
    tos = 0;
}

// Push a character
int stack::push (char ch) {
    if (tos == SIZE) {
        cout << "Stack is full\n";
        return 1;
    }
    stck[tos] = ch;
    tos++;
    return 0;
}

// Pop a character:
char stack::pop() {
    if (tos == 0) {
        cout << "\nStack is empty";
        return 0;
    }
    tos--;
    return stck[tos];
}

ostream& operator<< (ostream &out, stack &obj) {
    for (int i = 0; i < SIZE; ++i) {
        out << obj.pop() << " ";
    }
    out << "\n\n";
    return out;
}

int main() {
    stack obj1;
    for (char c = 'A'; c < 'D'; ++c) {
        obj1.push(c);
    }
    cout << obj1;

    stack obj2;
    for (char c = 'A'; c < 'N'; ++c) {
        obj2.push(c);
    }
    cout << obj2;

     
    return 0;
}