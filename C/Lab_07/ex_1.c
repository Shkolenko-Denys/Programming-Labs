/*-------------------------------------------------------------------<Header>-
 Name: ex_1.c
 Title: Шифр Цезаря
 Description: —
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <ctype.h> /* islower, isupper */

void code_letter(char arr[27], char ch, int code);

int main(void) {
    char lower[27] = "abcdefghijklmnopqrstuvwxyz";  // with '\0'
    char upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ch;
    int code;
    printf("Enter code number: ");
    scanf("%d", &code);
    getchar();  // pass '\n'
    printf("Enter text: ");
    ch = getchar();
    printf("Encoded text: ");
    while (ch != '\n') {
        if (islower(ch)) {
            code_letter(lower, ch, code);
        } else if (isupper(ch)) {
            code_letter(upper, ch, code);
        } else {  // numbers, space, symbols
            putchar(ch);
        }
        ch = getchar();
    }
    printf("\n");
    return 0;
}

void code_letter(char arr[27], char ch, int code) {
    int index;
    for (int j = 0; j < 26; j++) {  // letter search
        if (arr[j] == ch) {
            index = j + code;
            if (index > 25) {
                index -= 26;
            }
            putchar(arr[index]);
            break; // letter found
        }
    }
}
