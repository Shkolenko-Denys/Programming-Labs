/*-------------------------------------------------------------------<Header>-
 Name: ex_2.c
 Title: Шифр Виженера
 Description: —
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <ctype.h> /* tolower, islower, isupper */
#define MAX_LEN 50  // code max length

void code_letter(char arr[27], char ch, int code);

int main(void) {
    char lower[27] = "abcdefghijklmnopqrstuvwxyz";  // with '\0'
    char upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ch;
    char codex[MAX_LEN];
    int code;  // current step in the codex
    printf("Enter code word: ");
    scanf("%s", codex);
    getchar();  // pass '\n'
    for (int i = 0; codex[i] != '\0'; i++) {
        codex[i] = tolower(codex[i]);
        for (int j = 0; j < 26; j++) {
            if (lower[j] == codex[i]) {
                codex[i] = j + 1;  // letter -> code
                break;  // letter found
            }
        }
    }
    printf("Enter text: ");
    ch = getchar();
    int k = 0;
    code = codex[k];
    printf("Encoded text: ");
    while (ch != '\n') {
        if (islower(ch)) {
            code_letter(lower, ch, code);
        } else if (isupper(ch)) {
            code_letter(upper, ch, code);
        } else {  // numbers, space, symbols
            putchar(ch);
        }
        // walk through the codex
        k++;
        if (codex[k] == '\0') {
            k = 0;
        }
        code = codex[k];
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
            break;  // letter found
        }
    }
}
