/*-------------------------------------------------------------------<Header>-
 Name: ex_11.cpp
 Title: —
 Description: Добавьте пользовательскую функцию ввода в класс strtype
 Задачи 9.9.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class strtype {
    string *p_str;
    int len;
public:
    strtype() { p_str = NULL; len = 0; }
    strtype(const string str);
    ~strtype() { delete p_str; }
    friend ostream& operator<< (ostream &out, const strtype &obj);
    friend istream& operator>> (istream &in, strtype &obj);
};

strtype::strtype(const string str) {
    len = str.size();
    p_str = new string(str);
    if (!p_str) {
        cout << "Allocation Error!\n";
        exit(1);
    }
}

ostream& operator<< (ostream &out, const strtype &obj) {
    out << *obj.p_str << "\n";
    return out;
}

istream& operator>> (istream &in, strtype &obj) {
    in >> *obj.p_str;
    return in;
}

int main() {
    strtype s1("This is a test."), s2("I HATE C++!!!!! :)");
    cout << s1 << "\n" << s2;

    cout << "Enter the text: ";
    cin >> s2;

    cout << s2 << "\n";

     
    return 0;
}