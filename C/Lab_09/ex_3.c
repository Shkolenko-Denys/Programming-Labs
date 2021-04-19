/*-------------------------------------------------------------------<Header>-
 Name: ex_3.c
 Title: —
 Description: Напишіть програму, в якій на вхід буде прийматись рядок із
 декількох чисел (чисел має бути не менше 10, тільки цілочисельного типу),
 після чого реалізуйте сортування введеного масиву наступними методами в такому
 порядку:
 1) алгоритм сортування методом Бульбашки (Bubble sort);
 2) тасування чисел, використовуючи шафл (Shuffle method);
 3) сортування методом Шелла (Shell sort);
 4) знову перетасувати через шафл;
 5) сортування методом Хоара (Hoor sort).
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(a, b) {int tmp; tmp=a; a=b; b=tmp;}
#define DIM 10

void bubble_sort(int a[], int dim);
void shuffle(int a[], size_t n);
void sort_shell(int a[], int dim);
void sort_hoor(int a[], int left, int right);
void showdata(int a[], int dim);

int main(void) {
    int data[DIM];
    int count = 0;
    do { // until it's entered correctly
        printf("Enter %d numbers: ", DIM);
        for (int i = 0; i < DIM; i++) {
            count += scanf("%d[^\n]", data + i);
        }
        fseek(stdin, 0, SEEK_END);  // buffer cleaning
    } while (count < 10);
    puts(" Bubble sort");
    bubble_sort(data, DIM);
    showdata(data, DIM);

    puts(" Shuffle method");
    shuffle(data, DIM);
    showdata(data, DIM);

    puts(" Shell sort");
    sort_shell(data, DIM);
    showdata(data, DIM);

    puts(" Shuffle method");
    shuffle(data, DIM);
    showdata(data, DIM);

    puts(" Hoor sort");
    sort_hoor(data, 0, DIM-1);
    showdata(data, DIM);
    return 0;
}

void bubble_sort(int a[], int dim) {
    for (int i = 0; i < dim - 1; i++) {
        for (int j = 0; j < dim - i - 1; j++) {
            if (*(a + j) > *(a + j + 1)) {
                SWAP(*(a + j), *(a + j + 1)); 
            } 
        }
    }
}

void shuffle(int a[], size_t n) {
    if (n > 1) {
        srand((unsigned) time(NULL));
        for (size_t i = 0; i < n-1; i++) {
            size_t j = i+rand() / (RAND_MAX / (n-i) + 1);
            SWAP(*(a + j), *(a + i));
        }
    }
}

void sort_shell(int a[], int dim) {
    for (int gap = dim/2; gap > 0; gap /= 2) {
        for (int i=gap; i<dim; i++) {
            for (int j=i-gap; j>=0 && *(a+j)>*(a+j+gap); j-=gap) {
                SWAP(*(a + j), *(a + j + gap));
            }
        }
    }
}

void sort_hoor(int a[], int left, int right) {
    int i = left, j = right, step = -1, condition = 1;
    if (left >= right) return; // nothing to sort
    do {
        if (condition == (*(a + i) > *(a + j))) {
            SWAP(*(a + i), *(a + j)); // swap values
            SWAP(i, j);    // swap indexes
            step *= -1;
            condition = !condition;
        }
        j += step;
    } while (j != i);
    sort_hoor(a, left, i-1);
    sort_hoor(a, i+1, right);
}

void showdata(int a[], int dim) {
    printf("Data: ");
    for (int i=0; i<dim; i++) {
        printf("%d ", *(a + i));
    }
    putchar('\n');
}
