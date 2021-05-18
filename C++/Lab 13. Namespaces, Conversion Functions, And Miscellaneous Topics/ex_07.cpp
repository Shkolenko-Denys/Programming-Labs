/*-------------------------------------------------------------------<Header>-
 Name: ex_07.cpp
 Title: —
 Description: В примере из Unit 14, в котором:
 explicit myclass(int x) { a = x; }
 explicit myclass(const char *str) { a = atoi(str); }
 если спецификатор explicit указать только для конструктора myclass(int),
 можно ли будет выполнить неявное преобразование также и для конструктора
 myclass(const char *)? Попробуйте и посмотрите, что получится. Попробуйте
 убрать const из myclass(const char *). Посмотрите и проанализируйте то, что
 вам сообщит компилятор.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

using namespace std;

class myclass {
    int a;
public:
    explicit myclass(int x) { a = x; }
    myclass(char *str) { a = atoi(str); }
    int geta() { return a; }
};

int main() {
    myclass obj1(4);
    myclass obj2 = "123";
    /*
    warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
    29 |     myclass obj2 = "123";
       |                    ^~~~~
    */
    cout << "obj1: " << obj1.geta() << endl;
    cout << "obj2: " << obj2.geta() << endl;
    return 0;
}