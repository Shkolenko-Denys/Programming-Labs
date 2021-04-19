#include <iostream>

using namespace std;

void order(int &x, int &y) {
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }
}

int main() {
    int a = 3, b = 2;
    cout << "a = 3, b = 2" << "\n\n";

    cout << "a: " << a << ' ' << "b: " << b << "\n";
    cout << "order(a, b)" << "\n\n";
    order(a, b);

    cout << "a: " << a << ' ' << "b: " << b << "\n";
    cout << "order(a, b)" << "\n\n";
    order(a, b);

    cout << "a: " << a << ' ' << "b: " << b << "\n\n";

    return 0;
}