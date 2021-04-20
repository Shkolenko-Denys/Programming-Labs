#include <iostream>
using namespace std;

class base {
    int a;
public:
    void load_a(int n) {
        a = n;
    }
    int get_a() {
        return a;
    }
};

class derived: public base {
    int b;
public:
    void load_b(int n) {
        b = n;
    }
    int get_b() {
        return b;
    }
};

int main() {
    derived x;
    x.load_a(1);
    x.load_b(2);
    derived y = x;
    cout << "< derived y = x >" << endl;
    cout << "X: a = " << x.get_a() << " b = " << x.get_b() << endl; 
    cout << "Y: a = " << y.get_a() << " b = " << y.get_b() << endl; 
    return 0;
}