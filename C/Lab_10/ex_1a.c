/*-------------------------------------------------------------------<Header>-
 Name: ex_1a.c
 Title: —
 Description: Напишіть програму, яка буде сортувати двовимірний масив
 (сортування методом Хоара)
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

#define DIM 10
#define SWAP(a, b) {int tmp; tmp=a; a=b; b=tmp;}

void sort_hoor(int a[], int left, int right);
void show_data(int nrows, int ncols, int const arr[][ncols]);

int main(void) {
    int data[][DIM] = { {-22, -4, 5, 8, 0, 23, 1, -9, 2, 35},
                        {-13, 5, 6, 9, 1, 0, 0, 0, 1, -13},
                        {12, 10, 8, 6, 15, -3, -3, 0, -3, 1},
                        {0, -45, 3, 12, 2, 0, -9, -7, 23, 21} };
    char line[] = "====================";
    int nrows = sizeof(data) / sizeof(*data);
    for (int i = 0; i < nrows; i++) {
        sort_hoor(data[i], 0, DIM - 1);
    }
    printf("%s Hoor sort %s\n", line, line);
    show_data(nrows, DIM, data);
    return 0;
}

void sort_hoor(int a[], int left, int right) {
    int i = left, j = right, step = -1, condition = 1;
    if (left >= right) return; // nothing to sort
    do {
        if (condition == (*(a + i) > *(a + j))) {
            SWAP(*(a + i), *(a + j)); // swap values
            SWAP(i, j);    // swap indexes
            step *= -1;
            condition = !condition;
        }
        j += step;
    } while (j != i);
    sort_hoor(a, left, i-1);
    sort_hoor(a, i+1, right);
}

void show_data(int nrows, int ncols, int const arr[][ncols]) {
    /* this function should not alter the array, it uses const */
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            printf("%5d", arr[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
