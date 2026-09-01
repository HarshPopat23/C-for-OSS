#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*Operation)(int, int, int *);

struct OperationEntry {
    const char *name;
    Operation function;
};

static int add(int left, int right, int *result)
{
    if ((right > 0 && left > INT_MAX - right) ||
        (right < 0 && left < INT_MIN - right)) {
        return 0;
    }
    *result = left + right;
    return 1;
}

static int subtract(int left, int right, int *result)
{
    if ((right < 0 && left > INT_MAX + right) ||
        (right > 0 && left < INT_MIN + right)) {
        return 0;
    }
    *result = left - right;
    return 1;
}

static int multiply(int left, int right, int *result)
{
    if (left > 0) {
        if ((right > 0 && left > INT_MAX / right) ||
            (right < 0 && right < INT_MIN / left)) {
            return 0;
        }
    } else if (left < 0) {
        if ((right > 0 && left < INT_MIN / right) ||
            (right < 0 && left < INT_MAX / right)) {
            return 0;
        }
    }
    *result = left * right;
    return 1;
}

static int divide(int left, int right, int *result)
{
    if (right == 0 || (left == INT_MIN && right == -1)) {
        return 0;
    }
    *result = left / right;
    return 1;
}

static int parse_int(const char *text, int *result)
{
    char *end;
    errno = 0;
    long value = strtol(text, &end, 10);
    if (errno == ERANGE || end == text || *end != '\0' || value < INT_MIN || value > INT_MAX) {
        return 0;
    }
    *result = (int) value;
    return 1;
}

int main(int argc, char *argv[])
{
    const struct OperationEntry operations[] = {
        {"add", add},
        {"subtract", subtract},
        {"multiply", multiply},
        {"divide", divide}
    };
    const size_t count = sizeof(operations) / sizeof(operations[0]);
    int left;
    int right;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s add|subtract|multiply|divide integer integer\n", argv[0]);
        return 1;
    }
    if (!parse_int(argv[2], &left) || !parse_int(argv[3], &right)) {
        fprintf(stderr, "Both operands must be valid integers\n");
        return 1;
    }

    for (size_t index = 0; index < count; index++) {
        if (strcmp(argv[1], operations[index].name) == 0) {
            int result;
            if (!operations[index].function(left, right, &result)) {
                fprintf(stderr, "Operation is invalid for these operands\n");
                return 1;
            }
            printf("%d\n", result);
            return 0;
        }
    }
    fprintf(stderr, "Unknown operation: %s\n", argv[1]);
    return 1;
}
