// This program has an error !!!

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class strtype {
    char *ptr;
public:
    strtype(char const *s);
    ~strtype() { delete[] ptr; }
    char *get() { return ptr; }
};

strtype::strtype(char const *s) {
    int len;
    len = strlen(s) + 1;
    ptr = new char[len];
    if (!ptr) { exit(1); }
    strcpy(ptr, s);
}

void show(strtype x) { // copy constructor call
    char *s;
    s = x.get();
    cout << s << "\n";
    // destructor call
}

int main() {
    strtype a("Hello"), b("Shit happens:");
    show(a);
    show(b);
    // destructor call again -- error
    return 0;
}
