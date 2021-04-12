/*
Задача 7.9. Из материала Unit7 вы должны были уяснить, что с помощью дружественной
оператор-функции можно определить разницу между префиксной и постфиксной
формами операторов инкремента и декремента точно так же, как это делалось с
помощью функций-членов (просто добавляете целый параметр при задании
постфиксной версии). Например, здесь приводятся префиксная и постфиксная версии 
оператора инкремента относительно класса coord :
coord operator ++(coord &obj); // prefix
coord operator ++(coord &obj, int notused); // postfix
Если оператор ++ находится перед операндом, то вызывается функция coord operator +
+(coord &obj). Если оператор ++ находится после операнда, вызывается функция coord
operator ++(coord &obj, int notused). В этом случае переменной notused будет
передано значение 0. Придумайте свой собственный пример (и класс тоже),
демонстрирующий все вышесказанное.
*/

#include <iostream>
 
class Cube {
    int num;
public:
    Cube() { num = 0; }
    Cube(int i) { num = i; }

    Cube& operator++(); // prefix
    Cube operator++(int); // postfix

    Cube& operator--(); // prefix
    Cube operator--(int); // postfix
 
    friend std::ostream& operator<< (std::ostream &out, const Cube &n);
};
 
Cube& Cube::operator++() {
    // If the value of the variable num is 7, then we reset the value of num to 1
    if (num == 7) {
        num = 1;
    } else { // Otherwise, just increment num by one
        ++num;
    }
    return *this;
}
 
Cube& Cube::operator--() {
    // If the value of the variable num is 0, then assign num the value 6
    if (num == 0) {
        num = 6;
    } else { // Otherwise, just decrease num by one
        --num;
    }
 
    return *this;
}
 
Cube Cube::operator++(int) {
    // Create a temporary object of the Cube class with the current value of the variable num
    Cube temp(num);
 
    // Use the prefix version increment operator to overload the postfix version increment operator
    ++(*this); // overload implementation
 
    // Returning a temporary object
    return temp;
}
 
Cube Cube::operator--(int) {
    Cube temp(num);

    --(*this);

    return temp; 
}
 
std::ostream& operator<< (std::ostream &out, const Cube &n) {
    out << n.num;
    return out;
}
 
int main() {
    Cube number(6);

    std::cout << std::endl;
    std::cout << number << " ";
    std::cout << ++number << " "; // called Cube::operator++();
    std::cout << number++ << " "; // called Cube::operator++(int);
    std::cout << number << " ";
    std::cout << --number << " "; // called Cube::operator--();
    std::cout << number-- << " "; // called Cube::operator--(int);
    std::cout << number << " ";
    std::cout << std::endl;
 
    return 0;
}