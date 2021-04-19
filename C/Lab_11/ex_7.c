/*-------------------------------------------------------------------<Header>-
 Name: ex_7.c
 Title: —
 Description: Напишіть програму, яка міститиме таку саму функцію, яка описана
 у попередньому завданні, але модифікуйте її. Нехай, тепер функція міститиме
 ще й другий параметр, котрий буде вказувати на те скільки саме слів потрібно
 зчитувати у кожному з рядків.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

#define SLEN 100
#define NROWS 5

void edit_arr(char arr[][SLEN], int nrows, int nchars);

int main(void) {
    char plan_for_day[NROWS][SLEN] = {
        "to finish laboratory work # 11", // as ... \0\0\0\0\0\0..
        "write a report # 11",
        "send the report at midnight",
        "write lectures on math",
        "go to sleep",
    };
    int n; // the number of chars
    do {
        fseek(stdin, 0, SEEK_END); // clipboard clearing
        fputs(" How many chars need to write? ", stdout);
    } while (!scanf("%d", &n));
    fseek(stdin, 0, SEEK_END); // clipboard clearing
    edit_arr(plan_for_day, NROWS, n);
    for (int i = 0; i < NROWS; i++) {
        puts(plan_for_day[i]); // automatically '\n' in the end
    }
    return 0;
}

void edit_arr(char arr[][SLEN], int nrows, int nchars) {
    for (int i = 0; i < nrows; i++) {
        for (int j = nchars; j < SLEN; j++) {
            arr[i][j] = '\0'; // zeroing
        }
    }
}