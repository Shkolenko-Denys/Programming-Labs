#include <iostream>

using namespace std;

class samp {
    int a;
public:
    samp() { a = 0; }
    samp(int num) { a = num; }
    int get_a() { return a; }
};

int main() {
    samp obj(88); // init obj a to 88
    samp objarray[10]; // non - initialized 10-element array
    cout << obj.get_a() << endl;
    for (int i = 0; i < 10; i++) {
        cout << objarray[i].get_a() << " ";
    }
    cout << endl;
    return 0;
}