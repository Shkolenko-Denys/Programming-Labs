/*-------------------------------------------------------------------<Header>-
 Name: ex_08.cpp
 Title: —
 Description: Попытайтесь на конкретных примерах оправдать введение ключевого
 слова explicit. Другими словами, объясните, почему неявное преобразование
 конструкторов в некоторых случаях может оказаться нежелательным.
 -------------------------------------------------------------------</Header>-*/

#include <string>
#include <iostream>
 
class MyString {
    std::string m_string;
public:
    MyString(int x) { // allocate string of size x
        m_string.resize(x, '!');
    }
 
    MyString(const char *string) { // allocate string to hold string value
        m_string = string;
    }
 
    friend std::ostream& operator<<(std::ostream& out, const MyString &s);
 
};
 
std::ostream& operator<<(std::ostream& out, const MyString &s) {
    out << s.m_string;
    return out;
}
 
void printString(const MyString &s) {
    std::cout << s;
}
 
int main() {
    MyString obj("Hello World");
    obj = 'x'; // Will compile and use MyString(int)
    std::cout << obj << "\n\n";
 
    printString('x'); // Will compile and use MyString(int)
    return 0;
}

/*
In the above example, the user is trying to initialize a string with a char.
Because chars are part of the integer family, the compiler will use the
converting constructor MyString(int) constructor to implicitly convert the
char to a MyString. The program will then print this MyString, to unexpected
results. Similarly, a call to printString('x') causes an implicit conversion
that results in the same issue.
*/