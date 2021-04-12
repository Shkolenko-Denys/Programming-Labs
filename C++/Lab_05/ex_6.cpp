#include <iostream>
#include <ctime>

using namespace std;

void cp_sleep(int milliseconds) { // Cross-platform sleep function
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
    while (clock() < time_end);
}

void myclreol(int pos = -1) {
    if (pos == -1) {
        cout << '\r';
        for(int i = 0; i < 80; i++) {
            cout << ' ';
        }
    }
    for(int i = 0; i < pos; i++) {
        cout << '\b'; 
    }
    for(int i = 0; i < pos; i++) {
        cout << ' ';
    }
}

int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    cout << "Your string: " << str;
    cp_sleep(3000);
    myclreol();
    cp_sleep(3000);
    cout << endl;
    cout << "Your string: " << str;
    cp_sleep(3000);
    myclreol(3);
    cout << endl;

    return 0;
}