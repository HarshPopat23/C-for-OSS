#include <stdio.h>

typedef int (*BinaryOperation)(int, int);

static int add(int left, int right)
{
    return left + right;
}

static int subtract(int left, int right)
{
    return left - right;
}

static int apply(BinaryOperation operation, int left, int right)
{
    return operation(left, right);
}

int main(void)
{
    BinaryOperation operations[] = {add, subtract};
    const char *names[] = {"add", "subtract"};
    size_t count = sizeof(operations) / sizeof(operations[0]);

    for (size_t index = 0; index < count; index++) {
        printf("%s: %d\n", names[index], apply(operations[index], 12, 5));
    }
    return 0;
}

