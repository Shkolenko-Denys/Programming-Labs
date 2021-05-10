/*-------------------------------------------------------------------<Header>-
 Name: ex_01.cpp
 Title: —
 Description: В Unit 7, Example 7.1 был создан класс coord для хранения
 целочисленных координат. Создайте родовую версию этого класса, чтобы можно
 было хранить координаты любого типа.
 Продемонстрируйте программу решения этой задачи.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

template <typename T>
class Coord {
    T x, y;
public:
    Coord() { x = y = 0; }
    Coord(const T &x, const T &y) {
        this->x = x;
        this->y = y;
    }
    T getx() { return x; }
    T gety() { return y; }
    void setx(const T &x) { this->x = x; }
    void sety(const T &y) { this->y = y; }
    template <typename Type>
    friend std::ostream& operator<< (std::ostream &out, const Coord<Type> &obj);
};

template <typename Type>
std::ostream& operator<< (std::ostream &out, const Coord<Type> &obj) {
    out << " X = " << obj.x << ", Y = " << obj.y;
    return out;
}

int main() {
    Coord<int> obj_1;
    Coord<double> obj_2(1, 2);
    Coord<char> obj_3('a', 'b');

    std::cout << obj_1 << "\n" << obj_2 << "\n" << obj_3 << "\n";
    return 0;
}