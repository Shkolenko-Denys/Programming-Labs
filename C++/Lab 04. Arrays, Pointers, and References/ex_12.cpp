#include <iostream>
using namespace std;

class Array {
    int row;
    int column;
    int **matrix;
public:
    Array(int r, int c);
    ~Array();
    void set(int r, int c, int num);
    int get(int r, int c);
};

Array::Array(int r, int c) {
    row = r;
    column = c;
    matrix = new int* [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int [column];
    }
}

Array::~Array() {
    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Array::set(int r, int c, int num) {
    if (r < 0 || r >= row || c < 0 || c >= column) {
        cout << "Bounds error!" << "\n";
        exit(1);
    }
    matrix[r][c] = num;
}

int Array::get(int r, int c) {
    if (r < 0 || r >= row || c < 0 || c >= column) {
        cout << "Bounds error!" << "\n";
        exit(1);
    }
    return matrix[r][c];
}

int main() {
    Array obj(2, 3);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
           obj.set(i, j, i + j); 
        }
    }
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
           cout << obj.get(i, j) << " "; 
        }
        cout << "\n";
    }
    cout << "\n";
    obj.set(100, 100, 100);
    return 0;
}