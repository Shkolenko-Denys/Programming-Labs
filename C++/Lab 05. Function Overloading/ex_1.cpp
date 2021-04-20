#include <iostream>
#include <cstring> // strcpy, strlen
#include <iomanip> // setw

using namespace std;

class strtype {
    char *p;
    unsigned int len;
public:
    strtype();
    strtype(const char *s, unsigned int size);
    ~strtype();
    char* getstring() { return p; }
    int getlength() { return len; }
};

strtype::strtype() {
    p = new char[255](); // zeroing
    if (!p) {
        cout << "Allocation error\n";
        exit(1);
    }
    len = 255;
}

strtype::strtype(const char *s, unsigned int size) {
    p = new char[size];
    if (!p) {
        cout << "Allocation error\n";
        exit(1);
    }
    if (strlen(s) >= size) {
        cout << "Error: length >= allocated memory\n";
        exit(1);
    }
    strcpy(p, s);
    len = size;
}

strtype::~strtype() {
    delete[] p;
}

void print(strtype &str, string &line) {
    cout << setw(20) << str.getstring() << " |"
         << setw(15) << str.getlength() << " |\n";
    cout << line;
}

int main() {
    string line(39, '-');
    line += '\n';

    cout << line;
    cout << setw(20) << "string" << " |" << setw(15) << "size" << " |\n";
    cout << line;

    strtype string_1;
    print(string_1, line);

    strtype string_2("Hello World!", 50);
    print(string_2, line);

    strtype string_3("I love C++ !", 13);
    print(string_3, line);

    strtype string_4("I love C++ !", 12);
    print(string_4, line);

    return 0;
}
