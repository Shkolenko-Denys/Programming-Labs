#include <iostream>

using namespace std;

class myclass {
public:
    myclass();
    myclass(const myclass &obj);
    myclass f();
    myclass g(myclass obj);
};

// Normal constructor
myclass::myclass() {
    cout << "Constructing normally\n";
}

// Copy constructor
myclass::myclass(const myclass &obj) {
    cout << "Constructing copy\n";
}

// Return an object.
myclass myclass::f() {
    myclass temp; // normal constructor call
    return temp;
}

myclass myclass::g(myclass obj) { // copy constructor call
    myclass temp = obj; // copy constructor call
    return temp;
}

int main() {
    myclass obj; // normal constructor call
    obj = obj.f();
    obj = obj.g(obj);
    return 0;
}