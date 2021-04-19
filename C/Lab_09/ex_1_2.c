/*-------------------------------------------------------------------<Header>-
 Name: ex_1_2.c
 Title: —
 Description: Напишіть програму, в якій реалізуйте виконання поставлених
 задач з використанням вказівників.
 2. Знаходження суми двох матриць (враховуйте всі необхідні перевірки)
 Розмірність та елементи матриць мають задаватися з клавіатури.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

void size_entry(int *h, int *len);
void elem_entry(int h, int len, int (*matrix)[len]);
void show_matrix(int h, int len, int (*matrix)[len]);

int main(void) {
    int h, len;
    size_entry(&h, &len);
    int a[h][len],
    b[h][len],
    sum[h][len];
    puts(" Enter elements of first matrix:");
    elem_entry(h, len, a);
    puts(" Enter elements of second matrix:");
    elem_entry(h, len, b);
    // adding corresponding elements of two arrays
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < len; col++) {
            *( *(sum + row) + col) = *( *(a + row) + col) + *( *(b + row) + col);
        }
    }
    puts("\n Entered First Matrix:");
    show_matrix(h, len, a);
    puts("\n Entered Second Matrix:");
    show_matrix(h, len, b);
    puts("\n Sum Of Matrix:");
    show_matrix(h, len, sum);
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