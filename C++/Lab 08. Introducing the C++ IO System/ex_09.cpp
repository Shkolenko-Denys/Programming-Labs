/*-------------------------------------------------------------------<Header>-
 Name: ex_09.cpp
 Title: —
 Description: В незавершенной программе имеется класс strtype. Для вывода
 строки на экран создайте пользовательскую функцию вывода:
 #include <iostream>
 #include <cstring>
 #include <cstdlib>
 using namespace std;
 class strtype {
     char *p;
     int len;
 public:
     strtype(char *ptr);
     ~strtype() { delete [] p; }
     friend ostream &operator <<(ostream &stream, strtype &obj);
 };
 strtype::strtype(char *ptr) {
     len = strlen(ptr)+1;
     p = new char(len);
     if (!p) {
     cout << "Allocation error\n";
     exit(1);
     }
     strcpy(p, ptr);
 }
 // Create operator << inserter function here.
 int main() {
     strtype s1("This is a test."), s2("I hate C++!");
     cout << s1 << '\n' << s2;
     return 0;
 }
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class strtype {
    string *p_str;
    int len;
public:
    strtype(const string str);
    ~strtype() { delete p_str; }
    friend ostream& operator<< (ostream &out, const strtype &obj);
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

int main() {
    strtype s1("This is a test."), s2("I HATE C++!!!!! :)");
    cout << s1 << "\n" << s2;
     
    return 0;
}