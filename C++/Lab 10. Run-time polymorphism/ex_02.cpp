/*-------------------------------------------------------------------<Header>-
 Name: ex_02.cpp
 Title: —
 Description: Напишите программу для копирования текстового файла. В процессе
 копирования преобразуйте каждый символ табуляции в соответствующее число
 пробелов.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("txt_ex_02.txt");
    if (!fin) {
        cerr << " txt_ex_02.txt could not be opened for reading!" << endl;
        exit(1);
    }
    ofstream fout("txt_ex_02_COPY.txt");
    if (!fout) {
        cerr << " txt_ex_02_COPY.txt could not be opened for writing!" << endl;
        exit(1);
    }

    char ch;
    while (fin.get(ch)) {
        if (ch == '\t') {
            fout << "    ";
        } else {
            fout.put(ch);
        }
    }
    fin.close();
    fout.close();

    cout << "\n Successfully :) \n" <<
    "By the way, this is a useful program! \n\n";
    return 0;
}