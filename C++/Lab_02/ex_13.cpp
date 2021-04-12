#include <iostream>
#include <cstring>
using namespace std;

void rev_str (char *str) {
    char temp[50];
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        temp[i] = str[len - i - 1];
    }
    temp[len] = '\0';
    strcpy(str, temp);
}

void rev_str (char *str, char *res) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        res[i] = str[len - i - 1];
    }
    res[len] = '\0';
}

int main () {
    char str[50];
    char res[50];
    cout << "Enter the string: ";
    cin >> str;
    rev_str(str, res);
    rev_str(str);
    cout << "First: " << str << endl;
    cout << "Second: " << res << endl;
    return 0;
}