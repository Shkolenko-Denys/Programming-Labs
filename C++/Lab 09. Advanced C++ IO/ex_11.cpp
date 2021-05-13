/*-------------------------------------------------------------------<Header>-
 Name: ex_11.cpp
 Title: —
 Description: Дан следующий класс. Напишите программу для вывода содержимого
 объекта данного класса в файл:
 class account {
     int custnum;
     char name[80];
     double balance;
 public:
     account(int c, char *n, double b) {
         custnum = c;
         strcpy(name, n);
         balance = b;
     }
 };
 Подсказка: Для этой цели создайте пользовательскую функцию вывода.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class account {
    int custnum;
    string name;
    double balance;
public:
    account(int c, string nm, double b) {
        custnum = c;
        name = nm;
        balance = b;
    }
    friend ostream& operator<< (ostream &out, account &obj);
};

ostream& operator<< (ostream &out, account &obj){
    out <<
    " custnum : " << obj.custnum << "\n" <<
    " name : " << obj.name << "\n" <<
    " balance : " << obj.balance << endl;
    return out;
}

int main() {
    account person1(10110, "Fergus", 1000.23);
    ofstream fout("text_doc_ex_11.txt");
    if (!fout) {
        cerr << " text_doc_ex_11.txt could not be opened for writing!" << endl;
        exit(1);
    }
    fout << person1;
    fout.close();

    cout << " Successfully :) \n\n";
     
    return 0;
}