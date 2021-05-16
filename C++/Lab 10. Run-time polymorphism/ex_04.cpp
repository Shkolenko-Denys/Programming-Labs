/*-------------------------------------------------------------------<Header>-
 Name: ex_04.cpp
 Title: —
 Description: Напишите инструкцию, которая устанавливает указатель записи на
 81-й байт в файле, связанном с потоком out.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>

using namespace std;

ostream& seekput81(ostream &out) {
    out.seekp(81);
    return out;
}

int main() {
    ofstream fout("txt_ex_04.txt");
    if (!fout) {
        cerr << " txt_ex_04.txt could not be opened for writing!" << endl;
        exit(1);
    }
    fout << seekput81 << " I LOVE C++ !!! ";
    fout.close();

    cout << "\n Successfully :) \n\n";
    return 0;
}