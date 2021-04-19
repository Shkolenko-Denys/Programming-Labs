/*-------------------------------------------------------------------<Header>-
 Name: ex_9.c
 Title: —
 Description: Напишіть програму, в якій розробіть функцію strncpy(s1, s2, n),
 що буде копіювати точно n символів із s2 в s1, обрізаючи s2 або додаючи в
 нього додаткові нульові символи. Цільовий рядок може бути ненульовим, у випадку
 якщо довжина s2 дорівнює n або більша. Функція повертає s1. Також, напишіть
 свою власну версію функції, яка буде виконувати подібні до системної функції
 дії; назвіть її mystrncpy(). Протестуйте функцію на завершеній програмі, яка
 використовуватиме цикл для введення вхідних значень для функції.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <string.h>

char *my_strncpy(char *s1, const char *s2, int n);

int main(void) {
    char s1[] = "Happy ";
    char s2[] = "New Year! Merry Christmas!";
    int n;
    do {
        fseek(stdin, 0, SEEK_END); // clipboard clearing
        fputs(" How many chars need to write? ", stdout);
    } while (!scanf("%d", &n));
    fseek(stdin, 0, SEEK_END); // clipboard clearing
    my_strncpy(s1, s2, n);
    puts(s1);
    return 0;
}

char *my_strncpy(char *s1, const char *s2, int n)  {
    int count = 0;
    char *tmp = s1 + strlen(s1); 
    while (count != n && *s2 != '\0') {
        *tmp++ = *s2++;
        count++; 
    }
    *tmp = '\0';
    return s1;
}
