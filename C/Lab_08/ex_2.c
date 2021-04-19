/*-------------------------------------------------------------------<Header>-
 Name: ex_2.c
 Title: —
 Description: Напишіть програму, яка буде приймати на вхід два значення a та b
 та переставляти на виході ці значення місцями. Наприклад, спочатку у
 зростаючому порядку, потім навпаки. Використовуйте вказівники (покажчики) для
 перерозподілу значень. Програма повинна працювати для будь-яких чисел, тому
 числі, якщо користувачеві захочеться ввести від’ємні числа або десяткові дроби
 (типи float або double).
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

void sort(double *pa, double *pb);

int main(void) {
    double a, b;
    do {
        fseek(stdin, 0, SEEK_END); // buffer cleaning
        printf(" Enter a, b separated by a whitespace: ");
    } while (scanf("%lf %lf", &a, &b) != 2);
    sort(&a, &b);
    printf(" %f, %f\n", a, b);
    printf(" %f, %f\n", b, a);
    return 0;
}
void sort(double *pa, double *pb) {
    if (*pa > *pb) {
        double t = *pa;
        *pa = *pb;
        *pb = t;
    }
}