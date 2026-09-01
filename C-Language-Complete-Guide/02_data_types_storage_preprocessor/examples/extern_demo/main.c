#include <stdio.h>

#include "counter.h"

int main(void)
{
    increment_counter();
    increment_counter();
    printf("global counter: %d\n", global_counter);
    return 0;
}

