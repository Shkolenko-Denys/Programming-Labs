/*-------------------------------------------------------------------<Header>-
 Name: ex_05.cpp
 Title: —
 Description: Напишите программу создания базового класса Num. В этом классе
 должно храниться целое и определяться виртуальная функция shownum(). Создайте
 два производных класса outhex и outoct, которые наследуют класс Num. Функция
 shownum() должна быть переопределена в производных классах так, чтобы
 осуществлять вывод на экран значений, в шестнадцатеричной и восьмеричной
 системах счисления соответственно.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <iomanip>

using namespace std;

class Num {
protected:
    int n;
public:
    Num() { n = 0; }
    Num(const int &num) { n = num; }
    virtual void shownum() const {
        cout << n << endl;
    }
};

class Outhex : public Num {
public:
    Outhex() { n = 0; }
    Outhex(const int &num) { n = num; }
    virtual void shownum() const override {
        cout << hex << n << endl;
    }
};

class Outoct : public Num {
public:
    Outoct() { n = 0; }
    Outoct(const int &num) { n = num; }
    virtual void shownum() const override {
        cout << oct << n << endl;
    }
};

int main() {
    Outhex outhex(100);
    Outoct outoct(100);

    Num &refNum1 = outhex;
    Num &refNum2 = outoct;
    
    cout << " refNum1: " << "\n";
    refNum1.shownum();
    cout << " refNum2: " << "\n";
    refNum2.shownum();
    return 0;
}