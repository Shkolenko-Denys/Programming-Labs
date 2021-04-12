#include <iostream>
#include <cstdlib> // strtol

using namespace std;

long mystrtol(const char *start, char **end, int base = 10) {
    return strtol(start, end, base);
}

int main() {
    char number[] = "21032021";
    char *end;
    long integer = mystrtol(number, &end);
    cout << integer << endl;
    return 0;
}