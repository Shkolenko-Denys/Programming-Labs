/*
Задача 7.12. Переделайте Example 7.10 (См. Unit7 "A Closer Look At The Assignment
Operator") так, чтобы относительно класса strtype перегрузить оператор [] . Этот
оператор должен возвращать символ по заданному индексу. Кроме этого, необходима
возможность задавать оператор [] в левой части инструкции присваивания. Покажите,
что ваша программа работает.
*/

#include <iostream>

using namespace std;

class strtype {
    char *arr;
    int size;
public:
    strtype(int size);
    ~strtype() { delete[] arr; }
    char& operator[] (int i);
};

strtype::strtype(int sz) {
    if (sz < 1) { exit(EXIT_FAILURE); }
    size = sz;
    arr = new char[size](); // zeroing
    if (!arr) { exit(EXIT_FAILURE); }
}

char& strtype::operator[] (int i) {
    if(i < 0 || i >= size) {
        cout << "Bounds error" << "\n";
        exit(EXIT_FAILURE);
    }
    return arr[i];
}

int main() {
    strtype obj(10);
    obj[1] = 'A'; // [] on left of =
    cout << "\n obj[1] = " << obj[1] << "\n";

    return 0;
}