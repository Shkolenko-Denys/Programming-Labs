/*-------------------------------------------------------------------<Header>-
 Name: ex_4.c
 Title: The Tower of Hanoi is a mathematical game or puzzle.
 Description: Напишіть програму для вирішення задачі Ханойських веж. Задача
 полягає в тому, що маючи 3 вежі та три кільця різного розміру на першій з них
 (у вигляді пірамідки), потрібно перемістити ці кільця на останню вежу так, щоб
 опинились на ній у тому самому порядку.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#define MAX_NRINGS 64  // max number of rings
int st[4][MAX_NRINGS];  // 1, 2, 3 - the pegs
int nr[4];  // number of rings on pegs
int nmoves;  // number of rings movement
// Print current position on pegs
void print_st(void) {
    for (int i = 1; i <= 3; i++) {
        printf("\n| ");
        for (int j = 0; j < nr[i]; j++) {
            printf("%d", st[i][j]);
        }
    }
    printf("\n");
}
// Reset
void init(int nrings) {
    for (nr[1] = 0; nrings > 0; nr[1]++, nrings--) {
        st[1][nr[1]] = nrings;
    }
    nr[2] = nr[3] = 0;  // All rings on peg#1
    nmoves = 0;
    print_st();
}
// Move one ring from peg#1 to peg#2
void move1(int n1, int n2) {
    st[n2][nr[n2]++] = st[n1][nr[n1]--];
    print_st();
    nmoves++;
}
// Move upper nrings from peg i1 to peg i3 i2 as temp
// using peg. 1 <= i1, i2, i3 <= 3
void hanoi(int nrings, int i1, int i2, int i3) {
    if (nrings == 1) {
        move1(i1, i3);
    } else {
        hanoi(nrings - 1, i1, i3, i2);
        move1(i1, i3);
        hanoi(nrings - 1, i2, i1, i3);
    }
}

int main(void) {
    int nrings;
    printf("Rings number: ");
    scanf("%d", &nrings);
    hanoi(nrings, 1, 2, 3);
    printf("All rings were moved.\n");
    printf("Moves: %d\n", nmoves);
    return 0;
}