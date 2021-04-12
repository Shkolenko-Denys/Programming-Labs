#include <iostream>
#include <cstring> // strcpy
using namespace std;

int main() {
    string *p_string; // pointer to string
    p_string = new string(" This is a test.");
    cout << *p_string << "\n";
    delete p_string;

    char *p_char; // pointer to char in the string
    p_char = new char[100];
    strcpy(p_char, " This is a test.");
    cout << p_char << "\n";
    delete [] p_char;

    return 0;
}
