/*-------------------------------------------------------------------<Header>-
 Name: ex_4.c
 Title: —
 Description: Розробіть та запрограмуйте власну функцію, яка отримуватиме N
 символів на вході (враховуючи blanks, newlines & tabs) та зберігатиме ці
 символи в масив, адреса якого передаватиметься як аргумент.
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
        puts(text);
        free(text); // freeing up memory space
    }
    return 0;
}

void get_text(int n, char *text) {
    for (int i = 0; i < n; i++) {
        text[i] = getchar();
    }
}