#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t count = 10;

    if (count > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Requested array is too large\n");
        return 1;
    }

    int *values = malloc(count * sizeof(*values));
    int *zeroed = calloc(count, sizeof(*zeroed));
    if (values == NULL || zeroed == NULL) {
        fprintf(stderr, "Allocation failed\n");
        free(values);
        free(zeroed);
        return 1;
    }

    for (size_t index = 0; index < count; index++) {
        values[index] = (int) (index * index);
        printf("%d %d\n", values[index], zeroed[index]);
    }

    free(values);
    free(zeroed);
    return 0;
}

