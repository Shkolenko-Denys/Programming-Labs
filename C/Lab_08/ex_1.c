/*-------------------------------------------------------------------<Header>-
 Name: ex_1.c
 Title: —
 Description: Напишіть програму, в якій створіть функцію, що буде рахувати та
 відповідно виводити на екран результати розрахунків периметра та площі кола.
 Для цього напишіть у створеній функції формули розрахунків, а радіус кола
 повинен передаватись в програму з консолі. Оскільки значення змінних мають
 змінюватись створеною функцією, а передаватись з головної функції програми, то
 в цьому випадку варто використовувати покажчики.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#define PI 3.14

void area_len(double *pr);

int main(void) {
    double r;
    do {
        fseek(stdin, 0, SEEK_END); // buffer cleaning
        printf(" Enter radius: ");
    } while (scanf("%lf", &r) != 1 || r <= 0);
    area_len(&r);
    return 0;
}
void area_len(double *pr) {
    double s = PI * (*pr) * (*pr),
        len = 2 * PI * (*pr);
    printf(" Area: %.2f\n", s);
    printf(" Length: %.2f\n", len);
}
