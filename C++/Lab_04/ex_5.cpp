#include <iostream>
#include <new> // std::bad_alloc

int main() {
    float *a;
    long *b;
    char *c;
    try {
        a = new float(5.5);
        b = new long(555555);
        c = new char('A'); 
    } catch (std::bad_alloc &ba) {
        std::cerr << "Error: " << ba.what() << "\n";
        return 1;
    }
    
    std::cout << "a = " << *a << "\n"
              << "b = " << *b << "\n"
              << "c = " << *c << "\n";

    delete a;
    delete b;
    delete c;

    return 0;
}