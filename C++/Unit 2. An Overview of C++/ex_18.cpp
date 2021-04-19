#include <iostream>
using namespace std;

class mybox {
    double v;
public:
    mybox (double l, double s, double h);
    void volume();
};

mybox::mybox (double l, double s, double h) {
    v = l * s * h;
}

void mybox::volume () {
    cout << "Volume: " << v << endl; 
}

int main () {
    mybox box (2.2, 4.36, 6.01);
    box.volume();
    return 0;
}