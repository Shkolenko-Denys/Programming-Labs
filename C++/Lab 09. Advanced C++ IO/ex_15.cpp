/*-------------------------------------------------------------------<Header>-
 Name: ex_15.cpp
 Title: —
 Description: Напишите программу для вывода на экран содержимого текстового
 файла в обратном порядке.
 Совет: Еще один раз обдумайте задание перед началом программирования.
 Решение проще, чем может показаться на первый взгляд. 
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    ifstream fin("text_doc_ex_15.txt", ios::binary);
    if (!fin) {
        cerr << " text_doc_ex_15.txt could not be opened for reading!" << endl;
        exit(1);
    }

    // Get the length of the file
    size_t size = 0;
    fin.seekg(0, ios::end);
    size = fin.tellg();

    // Start reading the file in reverse
    char ch;
    while (size--) {
        fin.seekg(size);
        fin.get(ch);
        cout << ch;
    }

    cout << "\n\n";
     
    return 0;
}