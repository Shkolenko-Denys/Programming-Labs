/*-------------------------------------------------------------------<Header>-
 Name: ex_2.c
 Title: —
 Description: Напишіть програму, яка буде порівнювати значення двох чисел, при
 цьому декілька разів запитуючи користувача про введення чисел, які необхідно
 порівняти. Для порівняння використовуйте умовний оператор «?».
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

int main(void) {
    int a, b;
    while (1) {
        printf("Enter a: ");
        scanf("%d", &a);
        printf("Enter b: ");
        scanf("%d", &b);
        fflush(stdin);
        (a > b) ? puts("a > b") : (a < b ? puts("a < b") : puts("a = b"));
        printf("\n");
        printf("To repeat? Enter y/n: ");
        if (getchar() != 'y') {
            break;
        }
    }
    return 0;
}