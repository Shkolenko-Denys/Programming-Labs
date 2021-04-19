/*-------------------------------------------------------------------<Header>-
 Name: ex_5.c
 Title: —
 Description: Напишіть програму, в якій надайте можливість користувачеві ввести
 чисельний масив або згенеруйте випадкові числа. Потім розробіть функцію, яка
 буде виводити на екран результат заданого масиву у реверсованому вигляді, тобто
 функція повинна перевертати масив чисел у зворотньому порядку.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <stdlib.h> // malloc, free, time
#include <time.h> // srand, rand

#define SWAP(a, b) {int tmp; tmp=a; a=b; b=tmp;}

void random_arr(int n, int *arr);
void manually_arr(int n, int *arr);
void reverse_arr(int n, int *arr);
void show_arr(int n, const int *arr);

int main(void) {
    int n, mode;
    int *arr;
    do {
        fseek(stdin, 0, SEEK_END); // buffer cleaning
        printf(" Enter quantity: ");
    } while (!scanf("%d", &n));
    arr = (int*)malloc(n * sizeof(int)); // memory allocation
    if (!arr) {
        puts(" Not Enough Memory");
    }
    else {
        printf(" Enter mode of filling the array:\n"
            "  0 - fill manually\n"
            "  1 - random generation\n");
        do {
            fseek(stdin, 0, SEEK_END); // buffer cleaning
            printf(" Enter mode: ");
        } while (!scanf("%d", &mode));
        if (mode) {
            random_arr(n, arr);
        } else {
            manually_arr(n, arr);
        }
        show_arr(n, arr);
        reverse_arr(n, arr);
        show_arr(n, arr);
        free(arr); // freeing up memory space
    }    
    return 0;
}

void random_arr(int n, int *arr) {
    /* in range -99..99 */
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 199 - 99;
    // formula: n = rand() % (max - min + 1) + min;
}

void manually_arr(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        do {
            fseek(stdin, 0, SEEK_END); // buffer cleaning
            printf(" array[%d] = ", i);
        } while (!scanf("%d", &arr[i]));
    }
}

void reverse_arr(int n, int *arr) {
    for (int i = 0; i < n / 2; i++) {
        SWAP(arr[i], arr[n - i - 1]);
    }
}

void show_arr(int n, const int *arr) {
    /* this function should not alter the array, it uses const */
    for (int i = 0; i < n; i++) {
        printf("%4d ", arr[i]);
    }
    putchar('\n');
}
