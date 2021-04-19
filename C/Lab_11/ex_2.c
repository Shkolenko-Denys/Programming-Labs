/*-------------------------------------------------------------------<Header>-
 Name: ex_2.c
 Title: —
 Description: Функція my_gets() представлена у прикладі з лекції може бути
 прописана в нотації вказівника, замість нотації масиву для усунення змінної i.
 Напишіть програму, в якій реалізуйте такий приклад.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

#define STR_LEN 50

char *my_gets(char *st, int n);

int main(void) {
    char str[STR_LEN + 1]; // include the '\0'
    fputs("  Input: ", stdout); /* fputs() - stay on this line, no '\n' */
    if (my_gets(str, STR_LEN + 1)) {
        printf(" Output: %s\n", str);
    }
    return 0;
}

char *my_gets(char *st, int n) {
    char *ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (*st != '\n' && *st != '\0')
            st++;
        if (*st == '\n')
            *st = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}