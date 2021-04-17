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
#include <cstdlib> // system()

using namespace std;

int main() {

    system("pause");
    return 0;
}