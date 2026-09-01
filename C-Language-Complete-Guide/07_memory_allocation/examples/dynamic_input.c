#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t count;

    printf("How many integers: ");
    if (scanf("%zu", &count) != 1 || count == 0 || count > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    int *values = malloc(count * sizeof(*values));
    if (values == NULL) {
        fprintf(stderr, "Allocation failed\n");
        return 1;
    }

    for (size_t index = 0; index < count; index++) {
        if (scanf("%d", &values[index]) != 1) {
            fprintf(stderr, "Invalid integer\n");
            free(values);
            return 1;
        }
    }

    long long sum = 0;
    for (size_t index = 0; index < count; index++) {
        sum += values[index];
    }
    printf("sum: %lld\n", sum);
    free(values);
    return 0;
}

