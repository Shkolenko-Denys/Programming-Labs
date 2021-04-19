#include <iostream>
#include <string>
#include <new> // bad_alloc

using namespace std;

class student {
    string *name;
    string *phone_number;
public:
    student(string name, string phone_number);
    ~student();
    string get_name() { return *name; }
    string get_phone_number() { return *phone_number; }
};

student::student(string name, string phone_number) {
    try {
        this->name = new string(name);
        this->phone_number = new string(phone_number);
    } catch (bad_alloc &ba) {
        cerr << "Error: " << ba.what() << "\n";
        exit(1);
    }
}

student::~student() {
    delete [] name;
    delete [] phone_number;
}

int main() {
    student *i = new student("Denys", "+38(099)033-99-71");
    cout << "Name: " << i->get_name() << "\n"
         << "Phone number: " << i->get_phone_number() << "\n";

    delete i;
    return 0;
}