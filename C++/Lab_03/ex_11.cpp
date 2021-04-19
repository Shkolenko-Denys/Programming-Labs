#include <iostream>
using namespace std;

class pr2; // use in pr1
class pr1 {
    int printing;
public:
    pr1() {
        printing = 0;
    }
    void set_print(int status) { printing = status; }
    friend bool inuse(pr1, pr2); // access to printing
};

class pr2 {
    int printing;
public:
    pr2() {
        printing = 0;
    }
    void set_print(int status) { printing = status; }
    friend bool inuse(pr1, pr2);
};

bool inuse(pr1 printer1, pr2 printer2) {
    return (printer1.printing || printer2.printing ? true : false);
}

int main() {
    pr1 p1; pr2 p2;
    cout << "Status: " << (inuse(p1, p2) ? "Used" : "Free") << endl;
    p1.set_print(1);
    cout << "Status: " << (inuse(p1, p2) ? "Used" : "Free") << endl;
    return 0;
}