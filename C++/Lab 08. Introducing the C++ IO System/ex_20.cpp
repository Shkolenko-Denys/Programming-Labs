/*-------------------------------------------------------------------<Header>-
 Name: ex_20.cpp
 Title: —
 Description: Напишите программу с классом watch, который бы играл роль обычных
 часов. Используя стандартные функции времени, создайте конструктор класса,
 который должен считывать и запоминать системное время. Для вывода этого времени
 на экран создайте пользовательскую функцию вывода.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <cstdlib>

using namespace std;

class Watch {
    int hour;
    int min;
    int sec;
public:
    Watch(time_t time) {
        tm* now = localtime(&time);
        hour = now->tm_hour;
        min = now->tm_min;
        sec = now->tm_sec;
    }
    friend ostream& operator<< (ostream &out, Watch &obj);
};

ostream& operator<< (ostream &out, Watch &obj) {
    out <<
    setw(2) << setfill('0') << obj.hour << ":" <<
    setw(2) << setfill('0') << obj.min << ":" <<
    setw(2) << setfill('0') << obj.sec << "\n\n";
    return out;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        Watch now(time(NULL));
        cout << now;
        Sleep(1000);
        system("cls");
    }
     
    return 0;
}