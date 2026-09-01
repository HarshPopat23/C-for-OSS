#include <stdio.h>

#define BUFFER_SIZE 128
#define SQUARE(x) ((x) * (x))

static int square_int(int value)
{
    return value * value;
}

int main(void)
{
    int value = 6;

    printf("buffer size: %d\n", BUFFER_SIZE);
    printf("macro square: %d\n", SQUARE(value));
    printf("function square: %d\n", square_int(value));

#ifdef DEBUG
    fprintf(stderr, "debug: value is %d\n", value);
#endif

    return 0;
}

