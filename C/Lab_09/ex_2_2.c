/*-------------------------------------------------------------------<Header>-
 Name: ex_2_2.c
 Title: —
 Description: Напишіть програму, в якій реалізуйте виконання поставлених задач
 з використанням вказівників.
 2. З клавіатури зчитуватиметься декілька слів (враховуйте перевірки, щоб
 унеможливити введення цифр чи інших символів), після чого вони виводитимуться
 на екран у відсортованому в алфавітному порядку вигляді (можна використовувати
 введення тільки латинських літер).
 -------------------------------------------------------------------</Header>-*/

#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define N 10
#define L 50

int isletters(char *arr);

int main(void) {
    char str[N][L], temp[L];
    printf("Enter %d words:\n", N);
    int k = 0;
    while (k < N) {
        scanf("%s[^\n]", *(str + k));
        if (!isletters(*(str + k))) {
            puts(" Wrong! Try again!");
            k--;
        }
        k++;
    } 
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (strcmp(*(str + i), *(str + j)) > 0) {
                strcpy(temp, *(str + i));
                strcpy(*(str + i), *(str + j));
                strcpy(*(str + j), temp);
            }
        }
    }
    puts("\nIn lexicographical order:");
    for (int i = 0; i < N; ++i) {
        puts(*(str + i));
    }
    return 0;
}

int isletters(char *arr) {
    for (int i = 0; *(arr + i) != '\0'; i++) {
        char elem = *(arr + i);
        if ((elem < 'a' || elem > 'z') && (elem < 'A' || elem > 'Z')) {
            return 0;
        }
    }
    return 1;
}