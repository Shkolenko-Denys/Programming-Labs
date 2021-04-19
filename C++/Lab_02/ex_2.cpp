#include <iostream>
using namespace std;
#define FEET_PER_METERS 3.2808399
#define INCHES_PER_METERS 39.3700787

int main () {
    int meters = 1;
    bool repeat = true;
    do {
        cout << "Enter meters: ";
        cin >> meters;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000,'\n');
        } else if (meters) {
            cout << "Feet: " << meters * FEET_PER_METERS << endl;
            cout << "Inches: " << meters * INCHES_PER_METERS << endl;
        } else {
            repeat = false;
        }
        cout << endl;
    } while (repeat);
    return 0;
}