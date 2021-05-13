/*-------------------------------------------------------------------<Header>-
 Name: ex_08.cpp
 Title: —
 Description: Напишите программу для записи в файл phones.txt данных типа:
 Ivan Tormozenko, +38067 415 5113
 Petro Siplusenko, +38068 212 5332
 Olena Kompailenko, +38050 202 5451
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    ofstream fout("phones.txt");
    if (!fout) {
        cerr << " phones.txt could not be opened for writing!" << endl;
        exit(1);
    }
    fout << "Ivan Tormozenko, +38067 415 5113" << endl;
    fout << "Petro Siplusenko, +38068 212 5332" << endl;
    fout << "Olena Kompailenko, +38050 202 5451" << endl;
    cout << "\nSuccessfully written to file\n\n";
    
    // fout.close();
    // When outf goes out of scope, the destructor of the ofstream class
    // will automatically close our file.

     
    return 0;
}