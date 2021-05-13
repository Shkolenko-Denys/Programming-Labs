/*-------------------------------------------------------------------<Header>-
 Name: ex_18.cpp
 Title: —
 Description: Создайте манипулятор для ввода, который должен считывать и
 отбрасывать все неалфавитные символы. При считывании первого алфавитного
 символа, манипулятор должен возвратить его во входной поток и закончить работу.
 Назовите манипулятор findalpha.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

istream& findalpha(istream &stream) {
    char ch;
    while (stream.get(ch)) {
        if (isalpha(ch)) {
            stream.unget(); // returns the last character read back to the stream
            return stream;
        }
    }
    return stream;
}

int main() {
    char ch;
    cout << " Input : ";
    cin >> findalpha >> ch; // reads again

    // clean up all that remained in the stream after extraction:
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << " Output: " << ch << "\n\n";

     
    return 0;
}