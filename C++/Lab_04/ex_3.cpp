#include <iostream>

class samp {
    int a, b;
public:
    samp(int n, int m) { a = n; b = m; }
    int get_a() { return a; }
    int get_b() { return b; }
};

int main() {
    samp obj[4] = {
        samp(1, 2),
        samp(3, 4),
        samp(5, 6),
        samp(7, 8)
    };

    samp *p;
    p = &obj[3];

    for (int i = 0; i < 4; i++) {
        std::cout << p->get_b() << ' ';
        std::cout << p->get_a() << "\n";
        p--;
    }
    std::cout << "\n";

    return 0;
}