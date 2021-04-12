/*-------------------------------------------------------------------<Header>-
 Name: ex_1c.c
 Title: —
 Description: Напишіть програму, яка буде сортувати двовимірний масив
 (sort_choose)
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

#define DIM 10
#define SWAP(a, b) {int tmp; tmp=a; a=b; b=tmp;}

void sort_choose(int a[], int dim);
void show_data(int nrows, int ncols, int const arr[][ncols]);

int main(void) {
	int data[][DIM] = { {-22, -4, 5, 8, 0, 23, 1, -9, 2, 35},
						{-13, 5, 6, 9, 1, 0, 0, 0, 1, -13},
						{12, 10, 8, 6, 15, -3, -3, 0, -3, 1},
						{0, -45, 3, 12, 2, 0, -9, -7, 23, 21} };
	char line[] = "==================="; 
	int nrows = sizeof(data) / sizeof(*data);
	for (int i = 0; i < nrows; i++) {
		sort_choose(data[i], DIM);
	}
	printf("%s Choose sort %s\n", line, line);
	show_data(nrows, DIM, data);
	return 0;
}

void sort_choose(int a[], int dim) {
	for (int i = 0; i < dim; i++) {
		for (int j = i + 1; j < dim; j++) {
			if (a[i] > a[j]) {
				SWAP(a[i], a[j]);
			}
		}
	}
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
