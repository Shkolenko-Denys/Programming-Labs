/* Задача 8.2. Переработайте программу Задача 8.1 так, чтобы перегрузить
операторы с использованием дружественных функций. */

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

    array& operator= (const array &obj) {
        for (int i = 0; i < SIZE; i++) {
            nums[i] = obj.nums[i];
        }
        return *this;
    }

    friend array operator+ (const array &obj1, const array &obj2);
    friend array operator- (const array &obj1, const array &obj2);
    friend bool operator== (const array &obj1, const array &obj2);
    friend ostream& operator<< (ostream &out, const array &arr);
};

array operator+ (const array &obj1, const array &obj2) {
    array temp;
    for (int i = 0; i < SIZE; i++) {
        temp.nums[i] = obj1.nums[i] + obj2.nums[i];
    }
    return temp;
}

array operator- (const array &obj1, const array &obj2) {
    array temp;
    for (int i = 0; i < SIZE; i++) {
        temp.nums[i] = obj1.nums[i] - obj2.nums[i];
    }
    return temp;
}

bool operator== (const array &obj1, const array &obj2) {
    for (int i = 0; i < SIZE; i++) {
        if (obj1.nums[i] != obj2.nums[i]) {
            return false;
        }
    }
    return true;
}

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