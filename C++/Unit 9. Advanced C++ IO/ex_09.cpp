/*-------------------------------------------------------------------<Header>-
 Name: ex_09.cpp
 Title: —
 Description: Напишите программу для подсчета числа слов в файле. Для простоты
 считайте, что словом является все, имеющее с двух сторон пробелы.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    ifstream fin("text_doc_ex_09.txt");
    if (!fin) {
        cerr << " text_doc_ex_09.txt cannot be opened for reading!" << endl;
        exit(1);
    }

    int count = 0;
    string str_input;

    while (fin) {
        fin >> str_input;
        if (fin) { ++count; }
    }
    fin.close();

    cout << " Words: " << count << "\n\n";

    system("pause");
    return 0;
}