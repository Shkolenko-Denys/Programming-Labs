#include <iostream>
#include <cstring>
using namespace std;

class strtype {
    char *p;
    int len;
    int size;
    public:
        strtype(const char *ptr);
        ~strtype();
        void show();
};

strtype::strtype (const char *string) {
    p = new char[50];
    len = strlen(string);
    strcpy(p, string);
}

strtype::~strtype () {
    cout << "Freeing p\n";
    delete[] p;
}

void strtype::show () {
    cout << p << " - length: " << len << endl;
}

int main () {
    strtype s1("This is a test"), s2("I like C++");
    s1.show();
    s2.show();
    return 0;
}