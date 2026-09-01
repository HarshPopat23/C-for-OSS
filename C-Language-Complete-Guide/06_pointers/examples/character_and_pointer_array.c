#include <stdio.h>

int main(void)
{
    char editable[] = "pointers";
    char *cursor = editable;
    const char *topics[] = {"integer pointer", "character pointer", "double pointer"};
    size_t count = sizeof(topics) / sizeof(topics[0]);

    while (*cursor != '\0') {
        if (*cursor == 'p') {
            *cursor = 'P';
        }
        cursor++;
    }
    printf("%s\n", editable);

    for (size_t index = 0; index < count; index++) {
        printf("%zu: %s\n", index + 1, topics[index]);
    }
    return 0;
}

