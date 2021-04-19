/*-------------------------------------------------------------------<Header>-
 Name: ex_2_1.c
 Title: —
 Description: Напишіть програму, в якій реалізуйте виконання поставлених задач
 з використанням вказівників.
 1. На вхід в програму має подаватись рядок із букв і символів, після чого
 символи повинні бути видалені, а рядок виводитиметься на екран уже тільки з
 буквами.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int main(void) {
    char text[SIZE];
    printf("Enter text: ");
    gets(text);
    int i = 0;
    while (*(text + i) != '\0') {
        if (isdigit(*(text + i)) || ispunct(*(text + i))) {
            for (int j = i; *(text + j) != '\0'; j++) {
                *(text + j) = *(text + j + 1);
            }
            i--;
        }
        i++;
    }
    printf("Result: %s\n", text);
    return 0;
}