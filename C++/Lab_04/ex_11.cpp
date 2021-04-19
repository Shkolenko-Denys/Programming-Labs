#include <iostream>

using namespace std;

void neg(int *num) {
    *num = -(*num);
    // *n *= -1;
}

void neg(int &num){
    num = -num;
    // n *= -1;
}

int main() {
    int num;
    do {
        do {
            if (cin.fail()) {
                cout << "Incorrect! Try again" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cout << "Enter the number: ";
            cin >> num;
        } while (cin.fail());
        neg(&num);
        std::cout << "Used pointer: " << num << "\n";
        neg(num);
        neg(num);
        std::cout << "Used reference: " << num << "\n\n";
    } while (num);

    return 0;
}