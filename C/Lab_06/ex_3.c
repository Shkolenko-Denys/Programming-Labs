/*-------------------------------------------------------------------<Header>-
 Name: ex_3.c
 Title: —
 Description: Напишіть програму, яка буде рахувати перші 10 значень функції
 косинуса. Виконайте програму двома способами: у першому використайте вже
 реалізовану функції cos() з бібліотеки <cmath.h>, а у другому випадку напишіть
 свою власну функцію, яка буде рахувати значення косинуса, для цього
 скористайтесь формулою.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <math.h>

int factorial (int n);
double mycos (double x);

int main (void) {
    double x;
    printf(" x \t\tmycos(x)\t\tcos(x)\n");
    for (x = 0; x < 1; x += 0.1) {
        printf("%.1f\t%.15f\t%.15f\n", x, mycos(x), cos(x));
    }
}

int factorial (int n) {
     return (n < 2) ? 1 : n * factorial (n - 1);
}

double mycos(double x) {
    double sum = 0;
    for(int i = 0; i < 10; i++)
        sum += pow(-1, i)*pow(x, 2*i)/factorial(2*i);
    return sum;
}