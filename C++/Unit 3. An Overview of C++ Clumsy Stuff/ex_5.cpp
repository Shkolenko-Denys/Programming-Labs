#include <iostream>
using namespace std;

inline int myabs(int a) {
    if (a < 0)
        return -a;
    return a;
}
inline long myabs(long a) {
    if (a < 0)
        return -a;
    return a;
}
inline double myabs(double a) {
    if (a < 0)
        return -a;
    return a;
}

int main() {
    int a; long b; double c;
    cout << "Int: ";
    cin >> a;
    cout << "Abs: " << myabs(a) << endl;
    cout << "Long: ";
    cin >> b;
    cout << "Abs: " << myabs(b) << endl;
    cout << "Double: ";
    cin >> c;
    cout << "Abs: " << myabs(c) << endl;
    return 0;
}