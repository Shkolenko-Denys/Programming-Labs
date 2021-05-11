/*-------------------------------------------------------------------<Header>-
 Name: ex_04.cpp
 Title: —
 Description: В следующей программе имеется ошибка. Исправьте ее с помощью
 оператора const_cast.
 #include <iostream>
 using namespace std;
 void f(const double &i) {
    i = 100;
 }
 int main() {
    double x = 98.6;
    cout << x << endl;
    f(x);
    cout << x << endl;
    return 0;
 }
 Объясните на двух примерах, почему оператор const_cast следует использовать
 только в самых крайних случаях.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>      // strtol

void f(const double &i) {
    const_cast<double &> (i) = 100;
}

// don't take it seriously
long mystrtol(const char *start, char **end, int base = 10) {
    char *p;
    p = const_cast<char *> (start);
    *p = *p + 8; // just an example
    return strtol(p, end, base);
}

// don't take it seriously
void set_password(const int &password) {
    // ...
    const_cast<int &> (password) = 0;
    // ...
    std::cout << " Password: " << password << "\n";
}

int main() {
    double x = 98.6;
    std::cout << x << std::endl;
    f(x);
    std::cout << x << std::endl;

    char number[] = "21032021";
    char *end;
    long integer = mystrtol(number, &end);
    std::cout << integer << std::endl;

    set_password(33433);
    return 0;
}