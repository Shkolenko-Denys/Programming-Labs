#include <iostream>

using namespace std;

int dif(int a, int b) {
    return a - b;
}

float dif(float a, float b) {
    return a - b;
}

void input(string name, int &num) {
    do {
        if (cin.fail()) {
            cout << "Incorrect! Try again" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "Enter int " << name << ": ";
        cin >> num;
    } while (cin.fail());
}

void input(string name, float &num) {
    do {
        if (cin.fail()) {
            cout << "Incorrect! Try again" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "Enter int " << name << ": ";
        cin >> num;
    } while (cin.fail());
}

int main() {
    int a, b;
    float c, d;
    input("a", a);
    input("b", b);
    input("c", c);
    input("d", d);

    cout << endl;
    cout << "int diff: " << dif(a, b) << endl;
    cout << "float diff: " << dif(c, d) << endl;

    return 0;
}
