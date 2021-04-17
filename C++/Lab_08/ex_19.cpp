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
#include <cstdlib> // system()

using namespace std;

int main() {

    system("pause");
    return 0;
}