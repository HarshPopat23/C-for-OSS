#include <stddef.h>
#include <stdio.h>

static int *find_value(int values[], size_t length, int target)
{
    for (size_t index = 0; index < length; index++) {
        if (values[index] == target) {
            return &values[index];
        }
    }
    return NULL;
}

int main(void)
{
    int values[] = {8, 3, 17, 9, 17};
    size_t length = sizeof(values) / sizeof(values[0]);
    int *match = find_value(values, length, 17);

    if (match == NULL) {
        puts("not found");
        return 0;
    }
    printf("found at index %td\n", match - values);
    *match = 100;
    printf("updated value: %d\n", values[2]);
    return 0;
}

