/*-------------------------------------------------------------------<Header>-
 Name: ex_08.cpp
 Title: program for implementation of Heap Sort
 Description: Создайте родовой класс для "пузырьковой" сортировки (или
 используйте любой другой известный вам алгоритм сортировки).
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

template <class T>
class HeapSort {
    T *arr;
    int n;
public:
    HeapSort(const int &n) {
        this->n = n;
        arr = new T[n];
        for (int i = 0; i < n; i++) {
            // 'a' represented in the ASCII encoding by decimal 97
            arr[i] = rand() % 26 + 97;
        }
    }
    ~HeapSort() {
        delete[] arr;
    }
    void heapify(int, int);
    void heapSort();

    template <typename Type>
    friend ostream& operator<< (ostream &out, const HeapSort<Type> &obj);
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    HeapSort<int> obj_1(10);
    cout << " obj_1 : " << obj_1 << "\n";
    obj_1.heapSort();
    cout << " sorted: " << obj_1 << "\n\n";

    HeapSort<char> obj_2(10);
    cout << " obj_2 : " << obj_2 << "\n";
    obj_2.heapSort();
    cout << " sorted: " << obj_2 << "\n\n";
    return 0;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
template <typename T>
void HeapSort<T>::heapify(int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(n, largest);
    }
}

// main function to do heap sort
template <typename T>
void HeapSort<T>::heapSort() {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(i, 0);
    }
}

template <typename Type>
ostream& operator<< (ostream &out, const HeapSort<Type> &obj) {
    for (int i = 0; i < obj.n; i++) {
        out << obj.arr[i] << " ";
    }
    return out; 
}