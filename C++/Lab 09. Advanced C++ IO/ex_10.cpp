/*-------------------------------------------------------------------<Header>-
 Name: ex_10.cpp
 Title: —
 Description: Измените решения Задач 7 и 9 так, чтобы в них использовались
 функции get(), put(), read() и/или write(). Думайте и используйте эти функции
 там, где они, по вашему мнению, принесут наибольшую пользу.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

size_t get_file_size(ifstream &stream) {
    size_t size = 0;
    stream.seekg(0, ios::end);
    size = stream.tellg();
    stream.seekg(0);
    return size;
}

int main() {

    // ex_07

    ifstream fin("text_doc_ex_10.txt", ios::binary);
    if (!fin) {
        cerr << " text_doc_ex_10.txt could not be opened for reading!" << endl;
        exit(1);
    }

    size_t file_size = get_file_size(fin);
    char *buffer = new char[file_size];

    fin.read(buffer, file_size);
    if (fin) {
        cout << file_size << " characters read successfully.\n\n";
    }
    else {
        cout << " Error: only " << fin.gcount() << " could be read\n\n";
    }

    ofstream fout("text_doc_ex_10_COPY.txt", ios::binary);
    if (!fout) {
        cerr << " text_doc_ex_10_COPY.txt could not be opened for writing!" << endl;
        exit(1);
    }
    fout.write(buffer, fin.gcount());
    delete[] buffer;

    cout << fin.gcount() << " characters copied.\n\n";

    fout.close();
    fin.close();

    // ex_09

    fin.open("text_doc_ex_10_COPY.txt");
    char ch;
    int count = 0;
    while (fin.get(ch)) {
        if (ch == ' ') {
            ++count;
        }
    }
    fin.close();

    // spaces on both sides: count - 1 
    cout << " Words: " << count - 1 << "\n\n";

     
    return 0;
}