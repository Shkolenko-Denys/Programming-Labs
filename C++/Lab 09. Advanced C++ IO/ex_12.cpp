/*-------------------------------------------------------------------<Header>-
 Name: ex_12.cpp
 Title: —
 Description: Перепишите программу из Example 10.11 так, чтобы вместо функции
 getline() использовать функцию get(). Будет ли отличаться работа программы?
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    char str[80];
    cout << " Input : ";
    cin.get(str, 80);
    cout << " Output: " << str << "\n\n";
    
    // the program only reads the first 79 characters (+ null terminator).
    // The rest of the characters remain in the input stream.
    // One important caveat: the get() function does not read the newline character!

    // the getline() function works exactly the same as the get() function,
    // but it can read newline characters.

     
    return 0;
}