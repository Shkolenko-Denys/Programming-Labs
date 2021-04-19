/*-------------------------------------------------------------------<Header>-
 Name: ex_6.c
 Title: —
 Description: Напишіть програму, в якій на вхід буде подаватись масив із
 декількох рядків. Розробіть функцію, яка буде зчитувати перше слово з кожного
 рядка на вході, записуватиме це слово до масиву, а всі інші слова цього рядка
 відкидатиме. Тобто, функція повинна зчитувати всі рядки масиву на вході,
 незалежно від їх кількості, але записувати до масиву лише перші слова, а все
 інше у кожному рядку ліквідувати. Для полегшення виконання завдання приймайте
 слово як набір символів виділених пробілами.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

#define SLEN 100
#define NROWS 5

void edit_arr(char arr[][SLEN], int nrows);

int main(void) {
    char plan_for_day[NROWS][SLEN] = {
        "to finish laboratory work # 11",
        "write a report # 11",
        "send the report at midnight",
        "write lectures on math",
        "go to sleep",
    };
    edit_arr(plan_for_day, NROWS);
    for (int i = 0; i < NROWS; i++) {
        puts(plan_for_day[i]); // automatically '\n' in the end
    }
    return 0;
}

void edit_arr(char arr[][SLEN], int nrows) {
    for (int i = 0; i < nrows; i++) {
        sscanf(arr[i], "%s", arr[i]); // reads to the first space
    }
}