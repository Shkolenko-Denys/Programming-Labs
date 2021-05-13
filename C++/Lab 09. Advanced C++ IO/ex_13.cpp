/*-------------------------------------------------------------------<Header>-
 Name: ex_13.cpp
 Title: —
 Description: Напишите программу для построчного считывания текстового файла и
 вывода каждой считанной строки на экран. Используйте функцию getline().
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "\n Error! Call: ex_13.exe text_doc_ex_13.txt" << endl;
    } else {
        ifstream fin(argv[1]);
        if (!fin) {
            cerr << " text_doc_ex_13.txt could not be opened for reading!" << endl;
            exit(1);
        }

        string strBuf;
        while (getline(fin, strBuf)) {
            cout << strBuf << endl;
        }
        fin.close();
    }
     
    return 0;
}