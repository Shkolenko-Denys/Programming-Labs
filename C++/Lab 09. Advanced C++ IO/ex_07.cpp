/*-------------------------------------------------------------------<Header>-
 Name: ex_07.cpp
 Title: —
 Description: Напишите программу для копирования текстового файла. Эта
 программа должна подсчитывать число копируемых символов и выводить на экран
 полученный результат. Почему это число отличается от того, которое выводится
 при просмотре списка файлов каталога?
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    ifstream fin("text_doc_ex_07.txt");
    if (!fin) {
        cerr << " text_doc_ex_07.txt could not be opened for reading!" << endl;
        exit(1);
    }
    ofstream fout("text_doc_ex_07_COPY.txt");
    if (!fout) {
        cerr << " text_doc_ex_07_COPY.txt could not be opened for writing!" << endl;
        exit(1);
    }
    fout << fin.rdbuf();
    fout.close();

    int size = 0;
    fin.seekg(0, ios::end);
    size = fin.tellg();
    cout << size << " characters copied.\n\n";
    fin.close();

     
    return 0;
}

// Почему это число отличается от того, которое выводится при просмотре списка файлов каталога?

/*
Во всех файловых системах, используемых Windows, дисковое пространство организовывается с
учетом размера кластеров (или размера единицы распределения). Размер кластера — минимальный
объем дискового пространства, который может быть выделен для хранения файла. Таким образом,
если размер файла не кратен размеру кластера, для его хранения необходимо использовать
дополнительное пространство (кратное размеру кластера).

Таким образом, хоть и наш файл имеет всего 30 символов (а значит 30 байт), в списке файлов каталога
мы увидим 1 кб, потому что размер кластера на диске установлен как 1024 байт.
*/