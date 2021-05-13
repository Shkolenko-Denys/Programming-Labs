/*-------------------------------------------------------------------<Header>-
 Name: ex_14.cpp
 Title: —
 Description: В Unit5 "Bounded Array" рассматривался простейший способ
 реализации безопасного массива, в котором для доступа к элементам массива
 использовались функции get() и put(). Перегрузка оператора [] позволяет
 создать такой массив гораздо проще. В практическом задании для Unit7 вам
 поручалось для создания безопасного массива реализовать в функции
 operator[]() контроль границ. Кроме этого, функция operator[]() должна
 возвращать ссылку на индексируемый элемент. В представленном ниже фрагменте
 сделана попытка добавить контроль границ массива, что позволяет при нарушении
 границ генерировать соответствующую ошибку.
 Подсказка: Вспомните, что безопасный массив - это массив, который
 инкапсулирован в классе, и при этом класс обеспечивает контроль границ
 массива. Благодаря перегрузке оператора [], работать с безопасным массивом
 можно так же, как с обычным.
 // A safe array example:
 ...
 class arraytype {
    ...
 };
 // Provide range checking for arraytype .
 int &arraytype::operator [](int i) {
    if (...) {
    cout << "Index value of " << i << " is out of bounds.\n";
    ...
 }
 ...
 }
 int main() {
    arraytype obj;
    // this generates a run - time error because size+100 is out of range:
    obj[size+100] = 99; // error
    return 0;
    }
 Итак, у вас есть уже класс с безопасным массивом. Переделайте его в родовой
 класс с безопасным массивом.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>

#define SIZE 10

using namespace std;

template <class T, int size = SIZE>
class arraytype {
    T arr[size];
public:
    arraytype() {
        for (int i = 0; i < size; i++) {
            arr[i] = (T) i / 2;
        }
    }
    T& operator[] (const int&);
};

template <class T, int size>
T& arraytype<T, size>::operator[] (const int &i) {
    if (i < 0 || i >= size) {
        throw i;
    }
    return arr[i];
}

int main() {
    arraytype<int> int_obj;
    arraytype<double> double_obj;
    cout << " Int array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << int_obj[i] << " ";
    }
    cout << "\n";

    cout << " Double array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << double_obj[i] << " ";
    }
    cout << "\n";

    try {
        int_obj[12] = 100;
    } catch (int i) {
        cout << "Index value of " << i << " is out of bounds.\n";
    }
    return 0;
}