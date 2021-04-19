#include <iostream>

class samp {
    int a;
public:
    samp(int n) { a = n; }
    int get_a() { return a; }
};

int main() {
    samp obj[4][2] = {
        1, 2,
        3, 4,
        5, 6,
        7, 8
    };
    
    samp *p = &obj[0][0];

    for (int i = 0; i < 4; i++) {
        std::cout << (p + i*2)->get_a() << " ";
        std::cout << (p + i*2 + 1)->get_a() << "\n";
    }
    std::cout << "\n";
    
    return 0;
}