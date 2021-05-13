/*-------------------------------------------------------------------<Header>-
 Name: ex_16.cpp
 Title: —
 Description: Напишите программу, которая попарно меняет местами символы в
 текстовом файле. Например, если в файле содержится "1234", то после выполнения
 программы там должно содержаться "2143".
 (Для простоты считайте, что в файле содержится четное число символов).
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    fstream iofile("text_doc_ex_16.txt");
    if (!iofile) {
        cerr << "text_doc_ex_16.txt could not be opened!" << endl;
        exit(1);
    }

    char ch1, ch2;
    while (iofile.get(ch1)) {
        iofile.get(ch2);

        iofile.seekg(-2, ios::cur);

        iofile.put(ch2);
        iofile.put(ch1);
    }
    iofile.close();
    
    cout << "\n Successfully :) \n\n";

     
    return 0;
}