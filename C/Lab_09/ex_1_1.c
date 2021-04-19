/*-------------------------------------------------------------------<Header>-
 Name: ex_1_1.c
 Title: —
 Description: Напишіть програму, в якій реалізуйте виконання поставлених
 задач з використанням вказівників.
 1. Знаходження транспонованої матриці будь-якого розміру.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

void size_entry(int *h, int *len);
void elem_entry(int h, int len, int (*matrix)[len]);
void show_matrix(int h, int len, int (*matrix)[len]);

int main(void) {
    int h, len;
    size_entry(&h, &len);
    int a[h][len];
    int transpose[len][h];
    puts(" Enter elements of matrix:");
    elem_entry(h, len, a);
    // finding the transpose of matrix
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < len; col++) {
            *( *(transpose + col) + row) = *( *(a + row) + col);
        }
    }
    puts("\n Entered Matrix:");
    show_matrix(h, len, a);
    puts("\n Transpose of Matrix:");
    show_matrix(len, h, transpose);
    return 0;
}

void size_entry(int *h, int *len) {
    do {
        fseek(stdin, 0, SEEK_END);  // buffer cleaning
        printf("Enter size with whitespace: ");
    } while (scanf("%d %d", h, len) != 2); // until it's entered correctly
}

void elem_entry(int h, int len, int (*matrix)[len]) {
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < len; col++) {
            do {
                fseek(stdin, 0, SEEK_END);  // buffer cleaning
                printf(" Enter elem a%d%d: ", row+1, col+1);
            } while (!scanf("%d[^\n]", *(matrix + row) + col));
        }
    }
}

void show_matrix(int h, int len, int (*matrix)[len]) {
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < len; col++) {
            printf("%3d", *(*(matrix + row) + col));
        }
        putchar('\n');
    }
}
