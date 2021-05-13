/*-------------------------------------------------------------------<Header>-
 Name: ex_04.cpp
 Title: —
 Description: Создайте родовой класс Input, который при вызове конструктора
 делает следующее:
 • выводит на экран строку-приглашение,
 • получает данные от пользователя,
 • повторно выводит на экран строку-приглашение, если вводимые данные не
 соответствуют заданному диапазону.
 Объекты типа Input должны объявляться следующим образом:
 Input obj("prompt message ", min_value, max_value)
 Здесь prompt message - это сообщение, появляющееся на экране в качестве
 приглашения для ввода. Минимальное и максимальное допустимые значения задаются
 с помощью параметров min_value и max_value соответственно. (Тип данных,
 вводимых пользователем, будет тем же самым, что и тип значений min_value и
 max_value.)
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <string>
#include <limits>

template <class T>
class Input {
    T value;
public:
    Input(const std::string &str, const T &min_value, const T &max_value) {
        do {
            std::cout << str;
            std::cin >> value;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << " Oops, that input is invalid. Please try again.\n\n";
                continue;
            }
            else { // remove unnecessary values
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (value < min_value || value > max_value);
    }
    const T& get_value() { return value; }
};

int main() {
    Input<int> input_1(" Enter the int: ", 5, 50);
    std::cout << "\n Value: " << input_1.get_value() << "\n\n";

    Input<char> input_2(" Enter the char: ", 'e', 'x');
    std::cout << "\n Value: " << input_2.get_value() << "\n\n";
    return 0;
}