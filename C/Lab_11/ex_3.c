/*-------------------------------------------------------------------<Header>-
 Name: ex_3.c
 Title: —
 Description: Напишіть програму, в якій буде реалізована наступна задача:
 функція strlen() приймає вказівник на рядок як аргумент та повертає значення
 довжини цього рядка.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

#define STR_LEN 50

int strlen(char *str);
char *my_gets(char *st, int n);

int main(void) {
    char str[STR_LEN + 1]; // include the '\0'
    fputs(" Input: ", stdout); /* fputs() - stay on this line, no '\n' */
    if (my_gets(str, STR_LEN + 1)) {
        printf(" Len = %d\n", strlen(str));
    }
    return 0;
}

int strlen(char *str) {
    int len = 0;
    while (*str++) {
        len++;
    }
    return len;
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