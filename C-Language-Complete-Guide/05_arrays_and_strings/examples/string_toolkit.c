#include <stddef.h>
#include <stdio.h>

static size_t cguide_strlen(const char text[])
{
    size_t length = 0;
    while (text[length] != '\0') {
        length++;
    }
    return length;
}

static int cguide_strcpy(char destination[], size_t capacity, const char source[])
{
    size_t length = cguide_strlen(source);
    if (length + 1 > capacity) {
        return 0;
    }
    for (size_t index = 0; index <= length; index++) {
        destination[index] = source[index];
    }
    return 1;
}

static int cguide_strcmp(const char left[], const char right[])
{
    size_t index = 0;
    while (left[index] != '\0' && left[index] == right[index]) {
        index++;
    }
    return (unsigned char) left[index] - (unsigned char) right[index];
}

static void cguide_strrev(char text[])
{
    size_t length = cguide_strlen(text);
    for (size_t left = 0, right = length; left < right && left < --right; left++) {
        char temporary = text[left];
        text[left] = text[right];
        text[right] = temporary;
    }
}

int main(void)
{
    char text[32];

    if (!cguide_strcpy(text, sizeof(text), "portable C")) {
        fprintf(stderr, "Copy failed\n");
        return 1;
    }
    printf("length: %zu\n", cguide_strlen(text));
    printf("compare with portable C: %d\n", cguide_strcmp(text, "portable C"));
    cguide_strrev(text);
    printf("reversed: %s\n", text);
    return 0;
}

