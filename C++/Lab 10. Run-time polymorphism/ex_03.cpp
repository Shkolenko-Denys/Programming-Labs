/*-------------------------------------------------------------------<Header>-
 Name: ex_03.cpp
 Title: —
 Description: Напишите программу для поиска в текстовом файле слова, заданного
 в командной строке. После выполнения программы на экране должно появиться
 число, обозначающее, сколько раз данное слово найдено в файле. Для простоты
 считайте следующее: все, что с обеих сторон окружено пробелами, есть слово.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "\n Error! Call: ex_03.exe SearchWord" << endl;
    } else {
        ifstream fin("txt_ex_03.txt");
        if (!fin) {
            cerr << " txt_ex_03.txt could not be opened for reading!" << endl;
            exit(1);
        }

        string str;
        size_t count = 0;
        while (fin >> str) {
            if (str == argv[1]) {
                ++count;
            }
        }
        fin.close();
        cout << " Amount: " << count << "\n\n";
    }
    return 0;
}