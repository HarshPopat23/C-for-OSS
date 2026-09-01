#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int parse_int(const char *text, int *result)
{
    char *end;
    long value;

    errno = 0;
    value = strtol(text, &end, 10);
    if (errno == ERANGE || end == text || *end != '\0' || value < INT_MIN || value > INT_MAX) {
        return 0;
    }
    *result = (int) value;
    return 1;
}

int main(int argc, char *argv[])
{
    long long sum = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s integer [integer ...]\n", argv[0]);
        return 1;
    }

    for (int index = 1; index < argc; index++) {
        int value;
        if (!parse_int(argv[index], &value)) {
            fprintf(stderr, "Invalid integer: %s\n", argv[index]);
            return 1;
        }
        sum += value;
    }

    printf("sum: %lld\n", sum);
    return 0;
}

