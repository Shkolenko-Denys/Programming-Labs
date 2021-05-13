/*-------------------------------------------------------------------<Header>-
 Name: ex_07.cpp
 Title: —
 Description: Создайте родовую функцию, возвращающую сумму значений элементов
 массива.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

template <typename T>
T find_frequent(T *array, const int &n) {
    T sum = (T)0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;
}

int main() {
    int array_1[5] = {1, 2, 2, 4, 3};
    char array_2[2] = {'A', 'A'};

    cout << " array_1: " << find_frequent(array_1, 5) << "\n";
    cout << " array_2: " << find_frequent(array_2, 2) << "\n\n";
    return 0;
}