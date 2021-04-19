/*-------------------------------------------------------------------<Header>-
 Name: ex_1.c
 Title: —
 Description: Напишіть програму, яка здійснювати поворот квадрату 3x3 у різних
 напрямках. Напрямок повороту має вибирати користувач, тому передбачте для нього
 таку можливість.
 -------------------------------------------------------------------</Header>-*/

/*     Turns of the square
*    This program flips the square matrix of ANY DIMENSION in all directions,
*    not only 3 by 3. You only need to resize and fill in the initial matrix */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <Windows.h>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define RED 4
#define WHITE 15
#define edge 4  // the size can be changed

void rotate_left(int value, int row, int col, int res_square[edge][edge]);
void rotate_right(int value, int row, int col, int res_square[edge][edge]);
void rotate_180(int value, int row, int col, int res_square[edge][edge]);
void flip_vertical(int value, int row, int col, int res_square[edge][edge]);
void flip_horizontal(int value, int row, int col, int res_square[edge][edge]);

int main(void) {
    bool launch = true;  // permission to repeat the program
    char mode;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("color F0");  // white background, black font
    system("mode 60, 30");
    const int square[edge][edge] = {{1, 2, 3, 4},
                                    {5, 6, 7, 8},
                                    {9, 10, 11, 12},
                                    {13, 14, 15, 16}};
    int transposed[edge][edge];
    while (launch) {
        printf("Enter the operation of your choice:\n"
            "A. Rotate left\t\tB. Rotate right\n"
            "C. Rotate 180\t\tD. Flip vertical\n"
            "E. Flip horizontal\tQ. Quit\n");
        SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | BLUE));
        printf("Your choice: ");
        SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | BLACK));
        mode = getchar();
        fflush(stdin);  // clearing the clipboard
        mode = toupper(mode);  // ignore case
        switch (mode) {
            case 'A':
                for(int row = 0; row < edge; row++) {
                    for(int col = 0; col < edge; col++) {
                        rotate_left(square[row][col], row, col, transposed);
                    }
                }
                break;
            case 'B':
                for(int row = 0; row < edge; row++) {
                        for(int col = 0; col < edge; col++) {
                            rotate_right(square[row][col], row, col, transposed);
                        }
                    }
                break;
            case 'C':
                for(int row = 0; row < edge; row++) {
                        for(int col = 0; col < edge; col++) {
                            rotate_180(square[row][col], row, col, transposed);
                        }
                    }
                break;
            case 'D':
                for(int row = 0; row < edge; row++) {
                        for(int col = 0; col < edge; col++) {
                            flip_vertical(square[row][col], row, col, transposed);
                        }
                    }
                break;
            case 'E':
                for(int row = 0; row < edge; row++) {
                        for(int col = 0; col < edge; col++) {
                            flip_horizontal(square[row][col], row, col, transposed);
                        }
                    }
                break;
            case 'Q':
                launch = false;
                SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | RED));
                puts("See you!");
                SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | BLACK));
                break;
            default:
                SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | RED));
                puts("Incorrect mode!");
                SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | BLACK));
                launch = false;
                break;
        }
        if (launch == true) {
            puts("Transposed square:");
            SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | GREEN));
            for(int row = 0; row < edge; row++) {
                for(int col = 0; col < edge; col++) {
                    printf("%2d ", transposed[row][col]);
                }
                printf("\n");
            }
            SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | BLACK));
        }
        printf("\n");
    }
    return 0;
}

void rotate_left(int value, int row, int col, int res_square[edge][edge]) {
    int step = edge - 1;
    res_square[step - col][row] = value;
}

void rotate_right(int value, int row, int col, int res_square[edge][edge]) {
    int step = edge - 1;
    res_square[col][step - row] = value;
}

void rotate_180(int value, int row, int col, int res_square[edge][edge]) {
    int step = edge - 1;
    res_square[step - row][step - col] = value;
}

void flip_vertical(int value, int row, int col, int res_square[edge][edge]) {
    int step = edge - 1;
    res_square[step - row][col] = value;
}

void flip_horizontal(int value, int row, int col, int res_square[edge][edge]) {
    int step = edge - 1;
    res_square[row][step - col] = value;
}
