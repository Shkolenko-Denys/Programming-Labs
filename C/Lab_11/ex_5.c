/*-------------------------------------------------------------------<Header>-
 Name: ex_5.c
 Title: —
 Description: Модифікуйте програму з завдання 5 так, щоб вона зупинялась після
 N кількості аргументів на вході або після першої зустрічі на вході символів
 blank, tab або newline, незалежно від того, який з них зустрінеться першим.
 Не використовуйте в реалізації лише scanf() для зчитування даних.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <stdlib.h> // calloc, free

void get_text(int n, char *text);

int main(void) {
    int n; // the number of chars
    do {
        fseek(stdin, 0, SEEK_END); // clipboard clearing
        fputs(" How many chars need to read? ", stdout); // stay on this line
    } while (!scanf("%d", &n));
    fseek(stdin, 0, SEEK_END); // clipboard clearing
    /* allocating memory for the array and zeroing memory */
    char *text = (char*)calloc((n + 1), sizeof(char)); // (n + 1) for the last '\0'
    if (!text) { // if n is so large
        puts(" Not Enough Memory");
    }
    else {
        puts(" Enter the text:"); // automatically '\n' in the end
        get_text(n, text);
        puts(" Result:");
        fputs(text, stdout);
        free(text); // freeing up memory space
    }
    return 0;
}

void get_text(int n, char *text) {
    char ch;
    for (int i = 0; i < n; i++) {
        ch = getchar();
        if (ch == ' ' || ch == '\t' || ch == '\n')
            break;
        text[i] = ch;
    }
}