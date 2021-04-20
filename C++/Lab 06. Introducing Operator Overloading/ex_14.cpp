/*
Задача 7.14. Перегрузите операторы сдвига ≫ и ≪ относительно класса coord так,
чтобы стали возможными следующие типы операций:
obj << integer
obj >> integer
Удостоверьтесь, что ваши операторы действительно сдвигают значения х и у на
заданное количество разрядов.
*/

#include <iostream>

using namespace std;

class coord {
    int x, y;
public:
    coord(int x, int y) { this->x = x; this->y = y; }
    coord& operator<< (int i);
    coord& operator>> (int i);

    void show_xy() {
        cout << "X: " << x << ", Y: " << y << "\n\n";
    }
};

coord& coord::operator <<(int i) {
    x = x << i;
    y = y << i;
    return *this;
}

coord& coord::operator >>(int i) {
    x = x >> i;
    y = y >> i;
    return *this;
}

int main() {
    coord a(10, 3);

    a.show_xy();
    cout << " / a << 4 / " << endl;
    a << 4;
    a.show_xy();
    cout << " / a >> 6 / " << endl;
    a >> 6;
    a.show_xy();

    return 0;
}