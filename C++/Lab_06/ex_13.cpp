/*
Задача 7.13. Измените ваше решение Задачи 7.12 так, чтобы использовать оператор []
для индексирования динамического массива. То есть замените функции get() и put()
оператором [].
*/

#include <iostream>

using namespace std;

class arraytype {
    int *arr;
    int size;
public:
    arraytype(int sz);
    ~arraytype() { delete [] arr; }
    int& operator[] (int i);
};

arraytype::arraytype(int sz) {
    if (sz < 1) {
        exit(EXIT_FAILURE);
    }
    size = sz;
    arr = new int[size](); // zeroing
    if (!arr) {
        exit(EXIT_FAILURE);
    }
}

int& arraytype::operator[] (int i) {
    if (i < 0 || i >= size) {
        cout << "Bounds error !" << "\n";
        exit(EXIT_FAILURE);
    }
    return arr[i];
}

int main() {
    arraytype a(10);
    cout << " < a[0] = 100; > " << "\n\n";
    a[0] = 100;
    cout << a[0] << "\n\n";

    return 0;
}