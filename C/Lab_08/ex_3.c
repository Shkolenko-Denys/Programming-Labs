/*-------------------------------------------------------------------<Header>-
 Name: ex_3.c
 Title: —
 Description: Згадуючи той факт, що масив також є вказівником, напишіть
 програму, яка буде рахувати середнє значення для всіх елементів масиву a[].
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

int main (void) {
    const double a[20] = {
        0.228952, 0.568418, 0.820277, 0.117099, 0.755212,
        0.509299, 0.572073, 0.224526, 0.852861, 0.0612133,
        0.175636, 0.568243, 0.0100543, 0.702012, 0.0345108,
        0.146549, 0.189951, 0.144139, 0.261263, 0.474034
    };
    double s = 0;
    for (int i = 0; i < 20; i++)
        s += *(a+i);
    printf(" Average: %f\n", s / 20.);
    return 0;
}
