#include <iostream>
#include <cstring>
using namespace std;

class strtype {
    char *p;
    int len;
public:
    strtype(const char *ptr);
    ~strtype();
    friend char *get_string(strtype *p);
};
strtype::strtype(const char *ptr) {
    len = strlen(ptr);
    p = new char[len+1];
    if (!p) {
        cout << "Allocation error." << endl;
        exit(1);
    }
    strcpy(p, ptr);
}
strtype::~strtype() {
    delete[] p;
}
char *get_string(strtype *p) {
    return p->p;
}

int main() {
    strtype s("apple");
    char * p = new char[80];
    p = get_string(&s);
    cout << "Word: " << p << endl;
    return 0;
}