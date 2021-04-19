/* Задача 8.1. Дана следующая, почти законченная программа, добавьте недостающие
оператор-функции:

#include <iostream>

using namespace std;

class array {
    int nums[10];
public:
    array();
    void set(int n[10]);
    void show();
    array operator +(array obj2);
    array operator -(array obj2);
    array operator ==(array obj2);
};
array::array() {
    for (int i=0; i <10; i++) nums[i] = 0;
}
void array::set(int *n) {
    for (int i=0; i<10; i++) nums[i] = n[i];
}
void array::show() {
    for (int i=0; i<10; i++)
        cout << nums[i] << ' ';
    cout << "\n";
}
// Fill in operator functions.
int main() {
    array obj1, obj2, obj3;
    int i[10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10};
    obj1.set(i);
    obj2.set(i);
    obj3 = obj1 + obj2;
    obj3.show();
    obj3 = obj1 - obj3;
    obj3. show();
    if (obj1 == obj2)
        cout << "obj1 equals obj2\n";
    else
        cout << "obj1 does not equal obj2\n";
    if (obj1 == obj3)
        cout << "obj1 equals obj3\n";
    else
        cout << "obj1 does not equal obj3\n";
    return 0;
}
Перегруженный оператор + должен поэлементно складывать оба операнда.
Перегруженный оператор - должен вычитать все элементы правого операнда из
элементов левого. Перегруженный оператор == должен возвращать значение true,
если все элементы обоих операндов равны, в противном случае он должен возвращать
значение false. */

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

    array operator+ (const array &obj) {
        array temp;
        for (int i = 0; i < SIZE; i++) {
            temp.nums[i] = nums[i] + obj.nums[i];
        }
        return temp;
    }

    array operator- (const array &obj) {
        array temp;
        for (int i = 0; i < SIZE; i++) {
            temp.nums[i] = nums[i] - obj.nums[i];
        }
        return temp;
    }

    array& operator= (const array &obj) {
        for (int i = 0; i < SIZE; i++) {
            nums[i] = obj.nums[i];
        }
        return *this;
    }

    bool operator== (const array &obj) {
        for (int i = 0; i < SIZE; i++) {
            if (nums[i] != obj.nums[i]) {
                return false;
            }
        }
        return true;
    }

    friend ostream& operator<< (ostream &out, const array &arr);
};

ostream& operator<< (ostream &out, const array &arr) {
    for (int i = 0; i < SIZE; i++) {
        out << arr.nums[i] << " ";
    }
    return out;
}

int main() {
    const int n[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array obj1(n), obj2(n), obj3;
    cout << " obj1: " << obj1 << "\n";
    cout << " obj2: " << obj2 << "\n";
    cout << " obj3: " << obj3 << "\n\n";
    
    cout << "  / obj3 = obj1 + obj2 / " << "\n";
    obj3 = obj1 + obj2;
    cout << " obj3: " << obj3 << "\n";
    cout << "  / obj3 = obj1 - obj3 / " << "\n";
    obj3 = obj1 - obj3;
    cout << " obj3: " << obj3 << "\n\n";

    if (obj1 == obj2) {
        cout << " obj1 equals obj2" << "\n";
    }
    else {
        cout << " obj1 does not equal obj2" << "\n";
    }

    if (obj1 == obj3) {
        cout << " obj1 equals obj3" << "\n";
    }
    else {
        cout << " obj1 does not equal obj3" << "\n";
    }
    return 0;
}