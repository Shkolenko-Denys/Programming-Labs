/*-------------------------------------------------------------------<Header>-
 Name: ex_04.cpp
 Title: —
 Description: Создайте свой манипулятор вывода для отображения текущего
 системного времени и даты. Назовите этот манипулятор tdm().
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

ostream& tdm(ostream &out) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    out << "The current date/time is: " << asctime(timeinfo);
    return out;
}

int main() {
    cout << "\n" << tdm << "\n\n";

     
    return 0;
}