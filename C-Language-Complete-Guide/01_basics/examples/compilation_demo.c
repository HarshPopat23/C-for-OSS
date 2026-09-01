#include <stdio.h>

#define COURSE_NAME "Complete C Guide"

static int square(int value)
{
    return value * value;
}

int main(void)
{
    const int number = 7;
    printf("%s: square of %d is %d\n", COURSE_NAME, number, square(number));
    return 0;
}

