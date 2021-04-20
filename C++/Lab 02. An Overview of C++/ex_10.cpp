#include <iostream>
using namespace std;

char min (char a, char b) {
    return a < b ? a : b;
}
int min (int a, int b) {
    return a < b ? a : b;
}
double min (double a, double b) {
    return a < b ? a : b;
}

int main () {
    char a, b;
    int c, d;
    double e, f;

    cout << "Enter 2 char: ";
    cin >> a >> b;
    cout << "Enter 2 integers: ";
    cin >> c >> d;
    cout << "Enter 2 double: ";
    cin >> e >> f;

    cout << "Min char: " << min(a, b) << endl;
    cout << "Min integer: " << min(c, d) << endl;
    cout << "Min double: " << min(e, f) << endl;
    return 0;
}