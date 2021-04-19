#include <iostream>
using namespace std;

inline void func(int n) {
    while (n != 0) {
        cout << n-- << ' ';
    }
    cout << endl;
}

int main() {
    func(10);
    return 0;
}