#include <stdio.h>

int main(void)
{
    int a = 17;
    int b = 5;
    int flags = 0x05;

    printf("sum: %d\n", a + b);
    printf("integer quotient: %d\n", a / b);
    printf("remainder: %d\n", a % b);
    printf("floating quotient: %.2f\n", (double) a / b);
    printf("comparison: %d\n", a > b);
    printf("short circuit: %d\n", b != 0 && a / b > 2);
    printf("bitwise and: %d\n", flags & 0x01);
    printf("left shift: %d\n", flags << 1);
    printf("precedence: %d\n", 2 + 3 * 4);
    printf("explicit grouping: %d\n", (2 + 3) * 4);
    return 0;
}

