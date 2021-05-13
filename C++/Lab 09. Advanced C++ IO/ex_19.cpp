/*-------------------------------------------------------------------<Header>-
 Name: ex_19.cpp
 Title: —
 Description: Напишите программу копирования текстового файла. При копировании
 измените регистр всех букв.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    ifstream fin("text_doc_ex_19.txt");
    if (!fin) {
        cerr << " text_doc_ex_19.txt could not be opened for reading!" << endl;
        exit(1);
    }
    ofstream fout("text_doc_ex_19_COPY.txt");
    if (!fout) {
        cerr << " text_doc_ex_19_COPY.txt could not be opened for writing!" << endl;
        exit(1);
    }

    char ch;
    while (fin.get(ch)) {
        if (islower(ch)) {
            ch = toupper(ch);
        } else {
            ch = tolower(ch);
        }
        fout.put(ch);
    }

    fin.close();
    fout.close();

    cout << "\n Successfully :) \n\n";

     
    return 0;
}