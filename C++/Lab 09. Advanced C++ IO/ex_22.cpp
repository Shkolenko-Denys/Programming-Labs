/*-------------------------------------------------------------------<Header>-
 Name: ex_22.cpp
 Title: —
 Description: Создайте класс stack для хранения символов в файле, а не в массиве.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class stack {
    fstream file;
public:
    stack() {
        file.open("text_doc_ex_22.txt");
        if (!file) {
            cerr << "text_doc_ex_22.txt could not be opened!" << endl;
            exit(1);
        }
    }
    stack(char ch) {
        file.open("text_doc_ex_22.txt");
        if (!file) {
            cerr << " text_doc_ex_22.txt could not be opened!" << endl;
            exit(1);
        }
        file.put(ch);
    }
    void push(char ch) {
        file.put(ch);
    }
    char pop() {
        char ch;
        if (file.tellg() == 0) {
            cerr << " Stack is empty!\n\n";
            ch = '\0';
        } else {
            file.seekg(-1, ios::cur);
            ch = file.peek();
        }
        return ch;
    }
};

int main() {
    stack a('a');
    a.push('b');
    a.push('c');
    cout << a.pop() << endl;
    a.push('d');
    a.push('e');

    for (int i = 0; i < 4; ++i) {
        cout << a.pop() << " ";
    }
    cout << endl;

    cout << a.pop() << endl;

    stack b;
    b.push('k');
    b.push('l');
    b.push('m');
    b.push('n');
    cout << b.pop() << endl;
    b.push('o');
    b.push('p');
    
    for (int i = 0; i < 5; ++i) {
        cout << b.pop() << " ";
    }
    cout << endl;

    cout << b.pop() << endl;

     
    return 0;
}