/*-------------------------------------------------------------------<Header>-
 Name: ex_09.cpp
 Title: —
 Description: Используя массивы в качестве объектов ввода/вывода, напишите
 программу для копирования содержимого одного массива в другой, хотя мы с вами
 уже знаем, что это не самый эффективный способ решения подобной задачи.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <strstream>

using namespace std;

int main() {
    char *p;
    ostrstream outs; // Dynamic array

    outs << "HelloWorld!" << ends;
    p = outs.str(); // Freezes the dynamic buffer
    cout << p << "\n\n";

    istrstream ins(p);

    char str[80];

    ins >> str;
    cout << str << "\n";
    return 0;
}