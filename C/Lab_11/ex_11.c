/*-------------------------------------------------------------------<Header>-
 Name: ex_11.c
 Title: —
 Description: Напишіть програму, в якій реалізуйте функцію, що буде приймати
 на вхід символьний рядок та на виході друкувати цей рядок у зворотньому
 порядку. Вхідні дані у функцію повинні передаватись за допомогою циклів.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <string.h>

#define STR_LEN 100
#define SWAP(a, b) {int tmp; tmp=a; a=b; b=tmp;}

void reverse_arr(int n, char *arr);
char *my_gets(char *st, int n);

int main(void) {
    char str[STR_LEN + 1];
    char mode; // about continue the program
    do {
        puts(" Enter the sentence:");
        my_gets(str, STR_LEN + 1);
        int n = strlen(str);
        reverse_arr(n, str);
        puts(" Result:");
        puts(str);
        printf("\n Continue (y/n)? ");
        while ((mode = getchar()) == ' ' || mode == '\n' || mode == '\t'); // skip space
        fseek(stdin, 0, SEEK_END); // clipboard clearing
        putchar('\n');
    } while (mode == 'Y' || mode == 'y');
    return 0;
}

void reverse_arr(int n, char *arr) {
    for (int i = 0; i < n / 2; i++) {
        SWAP(arr[i], arr[n - i - 1]);
    }
}

char *my_gets(char *st, int n) {
    char *ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (*st != '\n' && *st != '\0') {
            st++;
        }
        if (*st == '\n') {
            *st = '\0';
        }
        else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}