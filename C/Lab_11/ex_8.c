/*-------------------------------------------------------------------<Header>-
 Name: ex_8.c
 Title: —
 Description: Напишіть програму, в якій розробіть функцію з назвою is_within().
 Ця функція повинна на місці своїх аргументів приймати символ і вказівник на
 рядок. Створіть умови, за яких функція буде повертати ненульове значення у
 тому випадку, коли символ буде наявним у рядку (тобто, коли у рядку є хоча б
 один елемент, то повертає значення true), в іншому випадку – за відсутності у
 рядку будь-яких елементів функція має повертати нульовий символ (false).
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

int is_within(char ch, char *str);

int main(void) {
    char secret_text[] = "Have a nice day!";
    char ch;
    char mode; // about continue the program
    puts("Secret text: **** * **** ****");

    do {
        fputs("Your char: ", stdout);
        ch = getchar();
        fseek(stdin, 0, SEEK_END); // clipboard clearing

        if (is_within(ch, secret_text)) {
            puts("So you guessed it");
        } else {
            puts("Did not guess!");
        }

        printf("\n Continue (y/n)? ");
        while ((mode = getchar()) == ' ' || mode == '\n' || mode == '\t'); // skip space
        fseek(stdin, 0, SEEK_END); // clipboard clearing
        putchar('\n');
    } while (mode == 'Y' || mode == 'y');
    return 0;
}

int is_within(char ch, char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch)
            return 1;
    }
    return 0;
}