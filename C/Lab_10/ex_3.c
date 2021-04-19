/*-------------------------------------------------------------------<Header>-
 Name: ex_3.c
 Title: —
 Description: Напишіть програму, в якій створіть наступні функції:
 void show1(const double arr1[], int n);
 void show2(const double arr2[][3], int n);
 де для show1() n – це кількість елементів,
 а для show2() n – це кількість рядків.
 Та реалізуйте для цих функцій наступні задачі:
 a) при виклику функція show1() має проходити складений літерал, що складається
 зі значень 8, 3, 9 та 2;
 б) при виклику функція show2() має проходити складений літерал, що складається
 зі значень 8, 3, 9 – значення першого рядка функції, та зі значень 5, 4 і 1 –
 як значення другого рядка функції show2().
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

void show1(const double arr1[], int n);
void show2(const double arr2[][3], int n);

int main(void) {
    // the compound literal that creates a nameless array
    show1((double[]){8, 3, 9, 2}, 4); 
    show2((double[][3]){ {8, 3, 9}, {5, 4, 1} }, 2);
    return 0;
}

void show1(const double arr1[], int n) {
    /* this function should not alter the array, it uses const */
    for (int i = 0; i < n; i++) {
        printf("%5.2f", arr1[i]);
    }
    putchar('\n');
}

void show2(const double arr2[][3], int n) {
    /* this function should not alter the array, it uses const */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5.2f", arr2[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}