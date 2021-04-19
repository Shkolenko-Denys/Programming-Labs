/*-------------------------------------------------------------------<Header>-
 Name: ex_3.c
 Title: Шифр "Сциталь"
 Description: —
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 200  // text max length

int main(void) {
    char text[MAX_LEN];
    int d,    // diameter
        len,  // text length
        index,
        past = 0; // use the past value of the index
    printf("Enter diameter: ");
    scanf("%d", &d);
    getchar();  // pass '\n'
    printf("Enter text: ");
    scanf("%[^\n]", text);
    len = strlen(text);
    char code_text[len + 1];  // with '\0'

    // fill the code_text with null characters
    for (int i = 0; i < len; i++)
        code_text[i] = '\0';

    for (int k = 0; k < len; k++) {  // move all characters
        index = past + d;
        if (index >= len)
            index -= len;
        while (code_text[index] != '\0') {  // meet the used place
            index++;
            if (index >= len)
                index -= len;
        }
        code_text[index] = text[k];
        past = index;

    }
    code_text[len] = '\0';
    printf("Encoded text: %s\n", code_text);
    return 0;
}
