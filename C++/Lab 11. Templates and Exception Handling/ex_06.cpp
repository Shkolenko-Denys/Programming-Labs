/*-------------------------------------------------------------------<Header>-
 Name: ex_06.cpp
 Title: —
 Description: Создайте родовую функцию, возвращающую значение элемента, который
 чаще всего встречается в массиве.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

template <typename T>
T find_frequent(T *array, const int &n) {
    T frequent = *array;
    int max_count = 1;
    int count;
    for (int i = 0; i < n - 1; i++) {
        count = 1;
        for (int j = i + 1; j < n; j++) {
            if (array[i] == array[j]) {
                ++count;
            }
        }
        if (count > max_count) {
            max_count = count;
            frequent = array[i];
        }
    }
    return frequent;
}

int main() {
    int array_1[10] = {1, 2, 2, 4, 3, 2, 2, 4, 3, 0};
    char array_2[10] = {'a', 'b', 'b', 'd', 'e', 'b', 'b', 'e', 'd', 'x'};

    cout << " array_1: " << find_frequent(array_1, 10) << "\n";
    cout << " array_2: " << find_frequent(array_2, 10) << "\n\n";
    return 0;
}