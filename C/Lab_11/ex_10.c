/*-------------------------------------------------------------------<Header>-
 Name: ex_10.c
 Title: —
 Description: Напишіть програму, в якій розробіть функцію string_in(), яка
 приймає два за аргументи два рядкові вказівники. Якщо другий string міститься
 в першому, то функція має повертати адресу, з якої починається включений рядок.
 Наприклад, задана функція з такими аргументами: string_in(“hats”, “at”),
 поверне адресу на символ «a» із виразу другого аргументу «at». В іншому
 випадку, коли перший аргумент буде міститись у другому, функція повинна
 повертати нуль вказівник. Запрограмуйте програму так, щоб для задання вхідних
 значень функції, використовувались цикли. Не забувайте робити перевірки на
 коректність введених даних.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <string.h>

#define STR_LEN 40

int string_in(char *s1, char *s2, int k); // k - iteration number
char *my_gets(char *st, int n);

int main(void) {
    char str1[STR_LEN + 1],
    str2[STR_LEN + 1];
    char mode; // about continue the program
    do {
        fputs(" Enter first word: ", stdout);
        if (my_gets(str1, STR_LEN + 1)) {
            fputs(" Enter second word: ", stdout);
            if (my_gets(str2, STR_LEN + 1)) {
                int index = string_in(str1, str2, 1);
                printf(" Index %d\n", index);
            }
        }
        printf("\n Continue (y/n)? ");
        while ((mode = getchar()) == ' ' || mode == '\n' || mode == '\t'); // skip space
        fseek(stdin, 0, SEEK_END); // clipboard clearing
        putchar('\n');
    } while (mode == 'Y' || mode == 'y');
    return 0;
}

int string_in(char *s1, char *s2, int k) { // k - iteration number
    if (k > 2) { // loop protection
        return -1; // in other cases
    }
    int i; // index
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (s1[i + j] != s2[j]) {
                break;
            }
            else if (j == len2 - 1) {
                return i; // s2 in s1
            }
        }
    }
    if (string_in(s2, s1, ++k) != -1) {
        return 0; // s1 in s2
    }
    else {
        return -1;
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