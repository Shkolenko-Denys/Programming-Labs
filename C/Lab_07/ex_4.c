/*-------------------------------------------------------------------<Header>-
 Name: ex_4.c
 Title: —
 Description: Напишіть програму, яка зберігатиме дуже довге значення числа.
 Наприклад факторіал числа 30.
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <ctype.h> /* isdigit */
#include <stdbool.h>
#include <time.h> /* clock */
#define DIMENSION 5  // the optimal dimension for a factorial from 0 to 10000

int main(void) {
    int num;
    printf("Enter an integer (from 0 to 10000): ");
    scanf("%d", &num);
    if (num < 0) {
        puts("Error! Factorial of a negative number doesn't exist.");
    }
    else if (num == 0) {
        puts("Factorial of 0 = 1");
    }
    else {
        double time = clock();
        int len = num * DIMENSION;  // space for digits in the array
        int arr[len];  // the array for each individual digit

        // fill the array with zeros
         for (int i = 0; i < len; i++)
             arr[i] = 0;

        // split number into digits and put in the array
        int copy_num = num;  // num will be changed
        for (int p = len - 1; num; p--) {
            arr[p] = num % 10;
            num /= 10;
        }

        // multiplication in a column
        for (int curr_num = copy_num - 1; curr_num > 1; curr_num--) {
            int product, whole = 0, rest;
            for (int j = len - 1; j > 0; j--) {
                product = curr_num * arr[j] + whole;
                whole = product / 10;
                rest = product % 10;
                arr[j] = rest;
            }
        }

        // print the result without zeros
        printf("Factorial of %d = ", copy_num);
        bool first_natural = false;  // met not zero
        for (int k = 0; k < len; k++) {
            if (arr[k] != 0 && !first_natural) {  // meet first not zero digit
                first_natural = true;
            }
            if (first_natural) {
                printf("%d", arr[k]);
            }
        }
        printf("\n");
        printf("Time: %.4lf sec\n", (double)(clock() - time) / CLOCKS_PER_SEC);
    }
    return 0;
}
