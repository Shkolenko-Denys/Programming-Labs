#include <iostream>
using namespace std;

int mypow (int a, int b) {
    int res = 1;
    for (int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

int main () {
    int a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;
    cout << "Result: " << mypow(a, b) << endl;
    return 0;
}