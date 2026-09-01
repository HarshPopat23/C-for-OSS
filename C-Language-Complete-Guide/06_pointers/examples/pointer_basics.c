#include <stddef.h>
#include <stdio.h>

int main(void)
{
    int value = 42;
    int *pointer = &value;
    int **double_pointer = &pointer;
    int values[] = {10, 20, 30, 40};
    const size_t length = sizeof(values) / sizeof(values[0]);

    printf("value: %d\n", value);
    printf("through pointer: %d\n", *pointer);
    **double_pointer = 55;
    printf("after double-pointer update: %d\n", value);

    printf("array through pointer arithmetic:");
    for (int *cursor = values; cursor < values + length; cursor++) {
        printf(" %d", *cursor);
    }
    putchar('\n');
    return 0;
}

