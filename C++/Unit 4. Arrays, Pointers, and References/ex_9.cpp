#include <iostream>
#include <iomanip> // std::setprecision

int main() {
    double *p = new double(-123.0987);
    std::cout << std::setprecision(7) << *p << "\n";
    delete p;
    
    return 0;
}