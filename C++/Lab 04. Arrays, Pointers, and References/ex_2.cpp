#include <iostream>
#include <iomanip> // setw

using namespace std;

class squares {
    int num, sqr;
public:
    squares() { // called for non-initialized arrays
        num = 0;
        sqr = 0;
    }
    squares(int a, int b) {
        num = a;
        sqr = b;
    }
    void show() {
        cout << setw(8) << num << setw(12) << sqr << "\n";
    }
};

squares make_sq(int num) {
    int sqr = num * num;
    squares sq(num, sqr);
    return sq;
}

void print_obj_arr(squares *obj_arr, int n) {
    for (int i = 0; i < n; i++) {
        obj_arr[i].show();
    }
    cout << "\n";
}

int main() {
    // for small numbers less than 10
    squares few_sq[10] {
        squares(1, 1),
        squares(2, 4),
        squares(3, 9),
        squares(4, 16),
        squares(5, 25),
        squares(6, 36),
        squares(7, 49),
        squares(8, 64),
        squares(9, 81),
        squares(10, 100)
    };

    cout << setw(8) << "number" << setw(12) << "square" << "\n";

    print_obj_arr(few_sq, 10);

    // for bigger numbers (more than 100)
    squares more_sq[10];
    for (int i = 0; i < 10; i++) {
        more_sq[i] = make_sq(i + 100);
    }

    print_obj_arr(more_sq, 10);

    return 0;
}