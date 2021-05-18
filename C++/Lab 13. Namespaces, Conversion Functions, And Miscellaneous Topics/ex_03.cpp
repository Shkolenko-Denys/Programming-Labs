/*-------------------------------------------------------------------<Header>-
 Name: ex_03.cpp
 Title: —
 Description: У вас есть класс:
 class Pwr {
    int base;
    int exp;
 public:
    Pwr(int b, int e) { base = b; exp = e; }
    // create conversion to integer here
 };
 Создайте функцию преобразования для превращения объекта типа Pwr в целое.
 Функция должна возвращать результат возведения в степень base^exp. 
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <limits>

using namespace std;

class Pwr {
    int base;
    int exp;
    int val;
public:
    Pwr(int b, int e) : base(b), exp(e) {
        if (exp < 0) {
            throw exp;
        } else if (!base && !exp) {
            throw "uncertainty";
        }
        val = 1;
        for( ; e > 0; e--) {
            val *= base;
        }
    }
    operator int() { return val; } // conversion to integer
};

int get_int(string invitation) {
    int num;
    // validating user input
    while (true) {
        cout << invitation;
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Oops, that input is invalid. Please try again.\n\n";
        }
        else { // remove unnecessary values
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return num;
}

int main() {
    int base = get_int(" Enter the base: ");
    int exp = get_int(" Enter the exp (exp >= 0): ");
    try {
        Pwr obj(base, exp);
        int result = obj;
        cout << base << "^" << exp << " = " << result << "\n\n";
    } catch (int i) {
        cerr << " Error: exp = " << i << " < 0 !\n";
    } catch (const char *str) {
        cerr << " Error: " << str << "\n";
    }
    return 0;
}