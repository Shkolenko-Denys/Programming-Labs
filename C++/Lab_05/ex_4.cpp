#include <iostream>
#include <cstdlib>

using namespace std;

class myclass {
    int *ptr;
public:
    myclass(int i);
    myclass(const myclass &copy_myclass);
    ~myclass() { delete ptr; }
    friend int getval(myclass obj); // copy constructor call
};

myclass::myclass(int i) {
    ptr = new int;
    if (!ptr) { exit(1); }
    *ptr = i;
}

myclass::myclass(const myclass &copy_myclass) { // сopy constructor
    ptr = new int;
    if (!ptr) { exit(1); }
    *ptr = *copy_myclass.ptr;
}

int getval(myclass obj) {
    return *obj.ptr; // get value
}

int main() {
    myclass a(1), b(2);
    cout << getval(a) << " " << getval(b) << "\n";
    cout << getval(a) << " " << getval(b) << "\n";
    return 0;
}
