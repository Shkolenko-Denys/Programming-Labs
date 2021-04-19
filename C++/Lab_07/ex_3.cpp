/* Задача 8.3. Используя класс и функции Задача 8.1, перегрузите оператор ++ с
помощью функции-члена класса, а оператор -- с помощью дружественной функции.
(Перегрузите только префиксные формы операторов ++ и --). */

#include <iostream>

#define SIZE 10

using namespace std;

class array {
private:
    int *nums;
public:
    array() { nums = new int[SIZE](); }
    array(const int* const n) {
        nums = new int[SIZE];
        for (int i = 0; i < SIZE; i++) {
            nums[i] = n[i];
        }
    }
    ~array() { delete[] nums; }

    array& operator++ () { // prefix increment
        for (int i = 0; i < SIZE; i++) {
            nums[i]++;
        }
        return *this;
    }
    friend array& operator-- (array &obj); // prefix decrement
    friend ostream& operator<< (ostream &out, const array &arr);
};

array& operator-- (array &obj) { // prefix decrement
    for (int i = 0; i < SIZE; i++) {
        obj.nums[i]--;
    }
    return obj;
}

ostream& operator<< (ostream &out, const array &arr) {
    for (int i = 0; i < SIZE; i++) {
        out << arr.nums[i] << " ";
    }
    return out;
}

int main() {
    const int n[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array obj(n);
    cout << "   obj: " << obj   << "\n";
    cout << " ++obj: " << ++obj << "\n";
    cout << "   obj: " << obj   << "\n";
    cout << " --obj: " << --obj << "\n";
    cout << "   obj: " << obj   << "\n";
    return 0;
}