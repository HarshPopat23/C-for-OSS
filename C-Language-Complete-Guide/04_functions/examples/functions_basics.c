#include <stdio.h>

static int maximum(int left, int right);
static long long factorial(unsigned int value);

static int maximum(int left, int right)
{
    return left > right ? left : right;
}

static long long factorial(unsigned int value)
{
    if (value <= 1U) {
        return 1;
    }
    return (long long) value * factorial(value - 1U);
}

int main(void)
{
    printf("maximum: %d\n", maximum(14, 27));
    printf("factorial of 10: %lld\n", factorial(10));
    return 0;
}

