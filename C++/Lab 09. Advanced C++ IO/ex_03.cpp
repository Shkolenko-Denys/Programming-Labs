/*-------------------------------------------------------------------<Header>-
 Name: ex_03.cpp
 Title: —
 Description: Дан следующий класс. Создайте для него пользовательские функции
 ввода и вывода.
 class date {
     char d[9]; // store date as string : mm/dd/yy
 public:
     // add inserter and extractor
 };
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Date {
    char d[9]; // store date as string : mm/dd/yy
public:
    Date() { d[9] = {'\0'}; }
    friend ostream& operator<< (ostream &out, Date &obj);
    friend istream& operator>> (istream &in, Date &obj);
};

ostream& operator<< (ostream &out, Date &obj) {
    out << obj.d;
    return out;
}

istream& operator>> (istream &in, Date &obj) {
    cout << " Month: ";
    int month;
    in >> month;
    obj.d[0] = '0' + (month / 10);
    obj.d[1] = '0' + (month % 10);

    cout << " Day: ";
    int day;
    in >> day;
    obj.d[3] = '0' + (day / 10);
    obj.d[4] = '0' + (day % 10);

    cout << " Year: ";
    int year;
    in >> year;
    obj.d[6] = '0' + (year - 2000) / 10;
    obj.d[7] = '0' + (year - 2000) % 10;

    obj.d[2] = obj.d[5] = '/';
    return in;
}

int main() {
    Date date;
    cin >> date;
    cout << date << "\n\n";

     
    return 0;
}