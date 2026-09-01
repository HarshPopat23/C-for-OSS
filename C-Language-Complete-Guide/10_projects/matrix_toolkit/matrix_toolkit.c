#include <stddef.h>
#include <stdio.h>

#define MAXIMUM_DIMENSION 4

struct Matrix {
    size_t rows;
    size_t columns;
    int data[MAXIMUM_DIMENSION][MAXIMUM_DIMENSION];
};

static void print_matrix(const struct Matrix *matrix)
{
    for (size_t row = 0; row < matrix->rows; row++) {
        for (size_t column = 0; column < matrix->columns; column++) {
            printf("%5d", matrix->data[row][column]);
        }
        putchar('\n');
    }
}

static int add(const struct Matrix *left, const struct Matrix *right, struct Matrix *result)
{
    if (left->rows != right->rows || left->columns != right->columns) {
        return 0;
    }
    result->rows = left->rows;
    result->columns = left->columns;
    for (size_t row = 0; row < result->rows; row++) {
        for (size_t column = 0; column < result->columns; column++) {
            result->data[row][column] = left->data[row][column] + right->data[row][column];
        }
    }
    return 1;
}

static void transpose(const struct Matrix *input, struct Matrix *result)
{
    result->rows = input->columns;
    result->columns = input->rows;
    for (size_t row = 0; row < input->rows; row++) {
        for (size_t column = 0; column < input->columns; column++) {
            result->data[column][row] = input->data[row][column];
        }
    }
}

static int multiply(const struct Matrix *left, const struct Matrix *right, struct Matrix *result)
{
    if (left->columns != right->rows) {
        return 0;
    }
    result->rows = left->rows;
    result->columns = right->columns;
    for (size_t row = 0; row < result->rows; row++) {
        for (size_t column = 0; column < result->columns; column++) {
            result->data[row][column] = 0;
            for (size_t index = 0; index < left->columns; index++) {
                result->data[row][column] += left->data[row][index] * right->data[index][column];
            }
        }
    }
    return 1;
}

int main(void)
{
    const struct Matrix left = {2, 3, {{1, 2, 3}, {4, 5, 6}}};
    const struct Matrix same_size = {2, 3, {{6, 5, 4}, {3, 2, 1}}};
    const struct Matrix right = {3, 2, {{7, 8}, {9, 10}, {11, 12}}};
    struct Matrix result = {0};

    puts("sum:");
    if (add(&left, &same_size, &result)) {
        print_matrix(&result);
    }

    puts("transpose of left:");
    transpose(&left, &result);
    print_matrix(&result);

    puts("product:");
    if (multiply(&left, &right, &result)) {
        print_matrix(&result);
    }
    return 0;
}

