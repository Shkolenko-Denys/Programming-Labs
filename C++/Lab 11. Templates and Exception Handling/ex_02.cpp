/*-------------------------------------------------------------------<Header>-
 Name: ex_02.cpp
 Title: —
 Description: Функция find() ищет объект в массиве. Она возвращает либо индекс
 найденного объекта (если его удалось найти), либо -1, если заданный объект
 не найден. Ниже представлен прототип конкретной версии функции find():
 int find(int object, int *list, int size) {
    // Параметр size задает количество элементов массива.
 }
 Переделайте функцию find() в родовую функцию и продемонстрируйте ваше решение
 в программе.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>

template <typename T>
int find(const T &object, const T *const list, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (list[i] == object) {
            return i;
        }
    }
    return -1;
}

// Two floating point numbers cannot be compared
bool is_equal(double x, double y) {
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}
template <>
int find(const double &object, const double *const list, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (is_equal(list[i], object)) {
            return i;
        }
    }
    return -1;
}

int main() {
    int int_arr[5] = {0, 1, 2, 3, 4};
    double double_arr[5] = {0.0, 1.1, 2.2, 3.3, 4.4};
    char char_arr[5] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << " elem 2 by index " << find(2, int_arr, 5) << "\n";
    std::cout << " elem 3.3 by index " << find(3.3, double_arr, 5) << "\n";
    std::cout << " elem e by index " << find('e', char_arr, 5) << "\n\n";

    system("pause");
    return 0;
}