/*-------------------------------------------------------------------<Header>-
 Name: ex_14.cpp
 Title: —
 Description: Вопрос для размышления: вернитесь к примерам первых 13-ти лекций.
 Подумайте о том, в каких из них функции-члены можно было бы сделать
 постоянными или статическими. Может быть это примеры, в которых определение
 пространств имен наиболее предпочтительно? Пары примеров будет достаточно.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

// Example #1
class coord {
    int x, y; // coordinate values
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }

    int get_x() const { return x; } // used const
    int get_y() const { return y; } // used const
    void set_x(int i) { x = i; }
    void set_y(int j) { y = j; }
};


// Example #2
class Num {
protected:
    int n;
public:
    Num() { n = 0; }
    Num(const int &num) { n = num; }
    virtual void shownum() const { // used const
        std::cout << n << std::endl;
    }
};

class Outhex : public Num {
public:
    Outhex() { n = 0; }
    Outhex(const int &num) { n = num; }
    virtual void shownum() const override { // used const
        std::cout << std::hex << n << std::endl;
    }
};