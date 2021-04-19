/*-------------------------------------------------------------------<Header>-
 Name: ex_2.c
 Title: —
 Description: Напишіть програму, яка буде знаходити адресу елементів для масиву:
 int data[30][100].
 a) одним способом для data[22][56];
 b) другим способом для data[22][0];
 c) третім способом для data[0][0].
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

int main(void) {
    int data[30][100] = {0}; // initialize array to zeros
    char line[] = " +--------------+---------------------+----------------+";
    printf("%s\n", line);
    printf(" |   data[x][y] |        code         |     address    |\n");
    printf("%s\n", line);
    printf(" | data[22][56] |  *(data + 22) + 56  | %p |\n", *(data + 22) + 56);
    printf(" | data[22][56] |       &data[22][56] | %p |\n", &data[22][56]);
    printf(" |  data[22][0] |           data + 22 | %p |\n", data + 22);
    printf(" |  data[22][0] |            data[22] | %p |\n", data[22]);
    printf(" |   data[0][0] |                data | %p |\n", data);
    printf(" |   data[0][0] |             data[0] | %p |\n", data[0]);
    printf(" |   data[0][0] |         &data[0][0] | %p |\n", &data[0][0]);
    printf("%s\n", line);
    return 0;
}
