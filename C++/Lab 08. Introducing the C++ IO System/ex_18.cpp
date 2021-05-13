/*-------------------------------------------------------------------<Header>-
 Name: ex_18.cpp
 Title: —
 Description: Создайте класс box для хранения размеров квадрата. Для вывода
 изображения квадрата на экран создайте пользовательскую функцию вывода.
 (Способ изображения выберите любой.)
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Box
{
    int a;
public:
    Box(int a = 8) : a(a)
    {
    }

    friend ostream& operator<< (ostream &out, const Box &obj);
};

ostream& operator<< (ostream &out, const Box &obj)
{
    out << setw(obj.a + 1) << setfill('*') << "\n";
    for (int i = 0; i < obj.a - 2; ++i)
    {
        out << "*" << setw(obj.a - 1) << setfill(' ') << "*" << "\n";
    }
    if (obj.a != 1)
    {
        out << setw(obj.a + 1) << setfill('*') << "\n";
    }
    return out;
}

int main()
{
    Box box1(1);
    cout << box1 << "\n";

    Box box2(2);
    cout << box2 << "\n";

    Box box3(3);
    cout << box3 << "\n";

    Box box4(4);
    cout << box4 << "\n";

    Box box10(10);
    cout << box10 << "\n";

     
    return 0;
}