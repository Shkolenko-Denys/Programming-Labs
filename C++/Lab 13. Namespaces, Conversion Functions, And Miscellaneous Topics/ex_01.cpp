/*-------------------------------------------------------------------<Header>-
 Name: ex_01.cpp
 Title: —
 Description: Переделайте представленную ниже программу так, чтобы в ней
 отсутствовала инструкция using namespace std.
 // Convert spaces to |s.
 #include <iostream>
 #include <fstream>
 using namespace std;
 int main(int argc, char *argv[]) {
    if (argc !=3) {
        cout << " Usage : CONVERT <input> <output>\n";
        return 1;
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    if (!fout) {
        cout << "Cannot open output file.\n";
        return 1;
    }
    if (!fin) {
        cout << "Cannot open input file.\n";
        return 1;
    }
    char ch;
    fin.unsetf(ios::skipws); // do not skip spaces
    while (!fin.eof()) {
        fin >> ch;
        if (ch == ' ') ch = '|';
        if (!fin .eof()) fout << ch;
    }
    fin.close();
    fout.close();
    return 0;
 }
 -------------------------------------------------------------------</Header>-*/

// Convert spaces to |s.
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << " Usage : CONVERT <input> <output>\n";
        return 1;
    }
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    if (!fout) {
        std::cout << "Cannot open output file.\n";
        return 1;
    }
    if (!fin) {
        std::cout << "Cannot open input file.\n";
        return 1;
    }
    char ch;
    fin.unsetf(std::ios::skipws); // do not skip spaces
    while (!fin.eof()) {
        fin >> ch;
        if (ch == ' ') ch = '|';
        if (!fin .eof()) fout << ch;
    }
    fin.close();
    fout.close();
    return 0;
}