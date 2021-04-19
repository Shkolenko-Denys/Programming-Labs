#include <iostream>
#include <cmath>
using namespace std;

double myroot (int a) {
    a = (double)a;
    return sqrt(a);
}
double myroot (long int a) {
    a = (double)a;
    return sqrt(a);
}
double myroot (double a) {
    return sqrt(a);
}

int main () {
    int a;
    long int b;
    double c;
    cout << "Enter the 3 numbers: ";
    cin >> a >> b >> c;
    cout << "Results: " << myroot(a) << ' ' << myroot(b) << ' ' << myroot(c);
}