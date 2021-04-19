#include <iostream>
using namespace std;

union integer {
    int n;
    integer(int num);
    char arr_n[(sizeof(int))];
    void swap();
};
integer::integer(int num) {
    n = num;
}

void integer::swap() {
    char temp = arr_n[0];
    arr_n[0] = arr_n[sizeof(int) - 1];
    arr_n[sizeof(int) - 1] = temp;
    cout << "Output: " << n << endl;
}

int main() {
    int number;
    do {
        cout << "Enter the number: ";
        cin >> number;
        integer myint(number);
        myint.swap();
        cout << endl;
    } while (number);
    return 0;
}