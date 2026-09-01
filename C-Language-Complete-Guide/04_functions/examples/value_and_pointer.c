#include <stdio.h>

static void ineffective_swap(int left, int right)
{
    int temporary = left;
    left = right;
    right = temporary;
    printf("inside ineffective swap: %d %d\n", left, right);
}

static int swap(int *left, int *right)
{
    if (left == NULL || right == NULL) {
        return 0;
    }
    int temporary = *left;
    *left = *right;
    *right = temporary;
    return 1;
}

int main(void)
{
    int first = 10;
    int second = 20;

    ineffective_swap(first, second);
    printf("after ineffective swap: %d %d\n", first, second);

    if (!swap(&first, &second)) {
        fprintf(stderr, "Swap failed\n");
        return 1;
    }
    printf("after pointer-based swap: %d %d\n", first, second);
    return 0;
}

