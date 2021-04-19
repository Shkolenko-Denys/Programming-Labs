/*-------------------------------------------------------------------<Header>-
 Name: ex_4.c
 Title: —
 Description: Напишіть програму, в якій створіть функції, кожна з яких
 виконуватиме певну дію:
 а) перша – повертатиме найбільше значення з масиву цілих чисел;
 б) друга – повертатиме індекс елемента з найбільшим значенням з масиву чисел
 типу double;
 в) третя – виводитиме результат різниці між найбільшим та найменшим елементами
 масиву типу double. Масиви можуть бути одновимірними, значення елементів мають
 вводитись з консолі. Не забувайте прописати перевірки на коректність вводу
 даних (щоб уникнути помилок з некоректними значеннями елементів і можливості
 виходу за границі масиву).
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <stdlib.h> // malloc, free

int max_int(const int arr[], int n);
int index_of_max(const double arr[], int n);
double diff_max_min(const double arr[], int n);

int main(void) {
    int n;
    int *int_arr;
    double *double_arr;
    do {
        fseek(stdin, 0, SEEK_END); // buffer cleaning
        printf(" Enter size of integer array: ");
    } while (!scanf("%d", &n));
    int_arr = (int*)malloc(n * sizeof(int)); // memory allocation
    if (!int_arr) {
        puts(" Not Enough Memory");
    }
    else {
        for (int i = 0; i < n; i++) {
            do {
                fseek(stdin, 0, SEEK_END); // buffer cleaning
                printf(" array[%d] = ", i);
            } while (!scanf("%d", int_arr + i));
        }
        printf(" max integer = %d\n\n", max_int(int_arr, n));
        free(int_arr); // freeing up memory space
    }
    do {
        fseek(stdin, 0, SEEK_END); // buffer cleaning
        printf(" Enter size of double array: ");
    } while (!scanf("%d", &n));
    double_arr = (double*)malloc(n * sizeof(double)); // memory allocation
    if (!double_arr) {
        puts(" Not Enough Memory");
    }
    else {
        for (int i = 0; i < n; i++) {
            do {
                fseek(stdin, 0, SEEK_END); // buffer cleaning
                printf(" array[%d] = ", i);
            } while (!scanf("%lf", double_arr + i));
        }
        printf(" index of max double = %d\n", index_of_max(double_arr, n));
        printf(" max - min = %g\n", diff_max_min(double_arr, n));
        free(double_arr); // freeing up memory space
    }
    return 0;
}

int max_int(const int arr[], int n) {
    /* this function should not alter the array, it uses const */
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int index_of_max(const double arr[], int n) {
    /* this function should not alter the array, it uses const */
    int index = 0;
    double max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

double diff_max_min(const double arr[], int n) {
    /* this function should not alter the array, it uses const */
    double max = arr[0],
        min = arr[0],
        diff;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    diff = max - min;
    return diff;
}