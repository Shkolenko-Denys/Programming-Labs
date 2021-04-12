#include <iostream>
using namespace std;

int main () {
    int time, salary;
    do {
        if (cin.fail()) {
            cout << "Incorrect! Try again" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }
        cout << "Enter the time: ";
        cin >> time;
    } while (cin.fail());

    do {
        if (cin.fail()) {
            cout << "Incorrect! Try again" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }
        cout << "Enter the salary: ";
        cin >> salary;
    } while (cin.fail());

    cout << "Total: " << time*salary << endl;

    return 0;
}