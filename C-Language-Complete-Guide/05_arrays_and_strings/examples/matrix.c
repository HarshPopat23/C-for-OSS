#include <stddef.h>
#include <stdio.h>

#define ROWS 2
#define COLUMNS 3

static void print_matrix(int matrix[ROWS][COLUMNS])
{
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t column = 0; column < COLUMNS; column++) {
            printf("%4d", matrix[row][column]);
        }
        putchar('\n');
    }
}

int main(void)
{
    const int left[ROWS][COLUMNS] = {{1, 2, 3}, {4, 5, 6}};
    const int right[ROWS][COLUMNS] = {{6, 5, 4}, {3, 2, 1}};
    int sum[ROWS][COLUMNS] = {{0}};

    for (size_t row = 0; row < ROWS; row++) {
        for (size_t column = 0; column < COLUMNS; column++) {
            sum[row][column] = left[row][column] + right[row][column];
        }
    }

    print_matrix(sum);
    return 0;
}
