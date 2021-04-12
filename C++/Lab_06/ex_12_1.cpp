// Задача 7.12. В Unit5 "Bounded Array" рассматривался простейший способ реализации
// безопасного массива, в котором для доступа к элементам массива использовались
// функции get() и put(). Перегрузка оператора [] позволяет создать такой массив гораздо
// проще. Для создания безопасного массива реализуйте в функции operator[]() контроль
// границ. Кроме этого, функция operator[]() должна возвращать ссылку на индексируемый
// элемент. В представленном ниже фрагменте сделана попытка добавить контроль границ
// массива, что позволяет при нарушении границ генерировать соответствующую ошибку.
// Подсказка: Вспомните, что безопасный массив - это массив, который инкапсулирован в
// классе, и при этом класс обеспечивает контроль границ массива. Благодаря перегрузке
// оператора [] , работать с безопасным массивом можно так же, как с обычным.
// // A safe array example:
// ...
// class arraytype {
//  ...
// };
// // Provide range checking for arraytype .
// int &arraytype::operator [](int i) {
//  if (...) {
//  cout << "Index value of " << i << " is out of bounds.\n";
//  ...
//  }
//  ...
// }
// int main() {
//  arraytype obj;
//  // this generates a runtime error because SIZE+100 is out of range:
//  obj[SIZE+100] = 99; // error
//  return 0;
// }
// Помните! Безопасный массив увеличивает расход ресурсов, что далеко не всегда может
// оказаться приемлемым. Именно из-за непроизводительного расхода ресурсов в C++ (в
// отличие от Java) отсутствует встроенный контроль границ массивов. Тем не менее, в тех
// приложениях, в которых желательно обеспечить контроль целостности границ,
// реализация безопасного массива может оказаться возможным вариантом решения.

#include <iostream>

using namespace std;

class arraytype {
    int *arr;
    int size;
public:
    arraytype(int size);
    ~arraytype() { delete[] arr; }
    int& operator[] (int i);
};

arraytype::arraytype(int sz) {
    if (sz < 1) { exit(EXIT_FAILURE); }
    size = sz;
    arr = new int[size];
    if (!arr) { exit(EXIT_FAILURE); }
}

int& arraytype::operator[] (int i) {
    if(i < 0 || i >= size) {
        cout << "Bounds error" << "\n";
        exit(EXIT_FAILURE);
    }
    return arr[i];
}

int main() {
    arraytype obj(10);
    obj[0] = 100;
    cout << obj[0] << "\n";
    obj[100] = 1000; // error

    return 0;
}