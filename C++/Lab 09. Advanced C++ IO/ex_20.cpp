/*-------------------------------------------------------------------<Header>-
 Name: ex_20.cpp
 Title: —
 Description: Напишите программу, которая считывает текстовый файл, а затем
 сообщает, сколько раз каждая буква алфавита появляется в файле.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    ifstream fin("text_doc_ex_20.txt");
    if (!fin) {
        cerr << " text_doc_ex_20.txt could not be opened for reading!" << endl;
        exit(1);
    }

    char ch;
    int *alphabet_nums;
    alphabet_nums = new int[26](); // zeroing

    while (fin.get(ch)) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ++alphabet_nums[ch - 'a'];
        }
    }
    fin.close();
    for (char c = 'a'; c <= 'z'; ++c) {
        cout << c << " : " << alphabet_nums[c - 'a'] << endl;
    }
    delete[] alphabet_nums;

     
    return 0;
}