#include <stddef.h>
#include <stdio.h>

#define ROWS 3
#define COLUMNS 4

int main(void)
{
    int matrix[ROWS][COLUMNS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int (*row_pointer)[COLUMNS] = matrix;

    for (size_t row = 0; row < ROWS; row++) {
        for (size_t column = 0; column < COLUMNS; column++) {
            printf("%3d", row_pointer[row][column]);
        }
        putchar('\n');
    }
    return 0;
}

