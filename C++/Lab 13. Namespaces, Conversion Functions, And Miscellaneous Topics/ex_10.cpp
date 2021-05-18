/*-------------------------------------------------------------------<Header>-
 Name: ex_10.cpp
 Title: —
 Description: Используя массивы в качестве объектов ввода/вывода, напишите
 программу для преобразования строки, содержащей значение с плавающей точкой,
 в число с плавающей точкой (double).
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <limits>
#include <string>
#include <strstream>

#define SIZE 80

using namespace std;

int main() {
    char str[SIZE];
    cout << " Enter string-num : ";
    cin >> str;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    double num;
    istrstream ins(str);
    ins >> num;

    cout << " Double-num : " << num << "\n";
    cout << " num + num = " << num + num << "\n\n";
    return 0;
}