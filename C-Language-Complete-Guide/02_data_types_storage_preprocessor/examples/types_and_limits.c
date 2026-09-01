#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool ready = true;

    printf("Bits in one byte: %d\n", CHAR_BIT);
    printf("char size: %zu\n", sizeof(char));
    printf("short size: %zu\n", sizeof(short));
    printf("int size: %zu, range: %d to %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("long size: %zu\n", sizeof(long));
    printf("long long size: %zu\n", sizeof(long long));
    printf("float digits of precision: %d\n", FLT_DIG);
    printf("double digits of precision: %d\n", DBL_DIG);
    printf("ready: %s\n", ready ? "true" : "false");
    return 0;
}

