#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct IntVector {
    int *data;
    size_t length;
    size_t capacity;
};

static int vector_append(struct IntVector *vector, int value)
{
    if (vector->length == vector->capacity) {
        size_t new_capacity = vector->capacity == 0 ? 4 : vector->capacity * 2;
        if (new_capacity < vector->capacity || new_capacity > SIZE_MAX / sizeof(*vector->data)) {
            return 0;
        }
        int *temporary = realloc(vector->data, new_capacity * sizeof(*vector->data));
        if (temporary == NULL) {
            return 0;
        }
        vector->data = temporary;
        vector->capacity = new_capacity;
    }
    vector->data[vector->length++] = value;
    return 1;
}

static void vector_destroy(struct IntVector *vector)
{
    free(vector->data);
    vector->data = NULL;
    vector->length = 0;
    vector->capacity = 0;
}

int main(void)
{
    struct IntVector vector = {NULL, 0, 0};

    for (int value = 1; value <= 20; value++) {
        if (!vector_append(&vector, value * 10)) {
            fprintf(stderr, "Could not grow vector\n");
            vector_destroy(&vector);
            return 1;
        }
    }

    printf("length: %zu, capacity: %zu\n", vector.length, vector.capacity);
    for (size_t index = 0; index < vector.length; index++) {
        printf("%d%c", vector.data[index], index + 1 == vector.length ? '\n' : ' ');
    }
    vector_destroy(&vector);
    return 0;
}

