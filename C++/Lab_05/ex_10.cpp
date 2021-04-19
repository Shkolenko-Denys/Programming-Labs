#include <iostream>

using namespace std;

string reverse(string str, int count = -1) {
    if (count == -1) {
        count = str.size();
    }
    for (int i = 0; i < count / 2; i++) {
        char temp = str[i];
        str[i] = str[count - i - 1];
        str[count - i - 1] = temp;
    }
    return str;
}

// string reverse(string str) {
//     int count = str.size();
//     for (int i = 0; i < count / 2; i++) {
//         char temp = str[i];
//         str[i] = str[count - i - 1];
//         str[count - i - 1] = temp;
//     }
//     return str;
// }

int main() {
    cout << "Input: Hello World!" << endl;
    string str_1 = reverse("Hello World!");
    cout << str_1 << endl;
    string str_2 = reverse("Hello World!", 5);
    cout << str_2 << endl;

    return 0;
}