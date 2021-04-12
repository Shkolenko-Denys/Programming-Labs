/*
Задача 7.10. Пусть дано следующее объявление класса, добавьте все необходимое для
создания типа динамический массив. То есть выделите память для массива и сохраните
указатель на эту память по адресу рtr. Размер массива в байтах сохраните в переменной
size. Создайте функцию put(), возвращающую ссылку на заданный элемент массива и
функцию get(), возвращающую значение заданного элемента. Обеспечьте контроль
границ массива. Кроме этого перегрузите оператор присваивания так, чтобы
выделенная каждому массиву такого типа память не была случайно повреждена при
присваивании одного массива другому.
class dynarray {
    int *ptr;
    int size;
public:
    dynarray(int s); // pass size of array in s
    int &put(int i); // return reference to element i
    int get(int i); // return value of element i
    // create operator =() function
};
*/

#include <iostream>

using namespace std;

class dynarray {
    int *ptr;
    int size;
public:
    dynarray(int s); // pass size of array in s
    ~dynarray();

    int &put(int i); // return reference to element i
    int get(int i); // return value of element i
    dynarray& operator= (dynarray& array);
    friend ostream& operator<< (ostream& out, const dynarray &a);
};

dynarray::dynarray(int s) { // pass size of array in s
    size = s;
    ptr = new int[size]; 
}

dynarray::~dynarray() {
    delete [] ptr; 
}

int& dynarray::put(int i) { // return reference to element i
    if (i < 0 && i > size) {
        exit(EXIT_FAILURE);
    }
    return ptr[i];
}

int dynarray::get(int i) { // return value of element i
    if (i < 0 && i > size) {
        exit(EXIT_FAILURE);
    }
    return ptr[i];
}

dynarray& dynarray::operator= (dynarray& array) {
    for (int i = 0; i < size; i++) {
        ptr[i] = array.get(i);
    }
    return *this;
}

ostream& operator<< (ostream& out, const dynarray &a) {
    for (int i = 0; i < a.size; i++) {
        out << a.ptr[i] << ' ';
    }
    out << "\n\n";
    return out;
}

int main() {
    dynarray arr1(10);
    dynarray arr2(20);

    for (int i = 0; i < 10; i++) {
        arr1.put(i) = i;
    }
    for (int i = 0; i < 20; i++) {
        arr2.put(i) = i * 2;
    }
    
    cout << "Array #1 : " << arr1;
    cout << "Array #2 : " << arr2;

    cout << " < arr1 = arr2 > " << "\n\n";
    arr1 = arr2;

    cout << "Array #1 : " << arr1;

    return 0;
}