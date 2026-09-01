#include <stdio.h>

int main(void)
{
    int sum = 0;
    int value = 5;
    int countdown = 3;

    for (int number = 1; number <= 5; number++) {
        sum += number;
    }
    printf("sum from 1 to 5: %d\n", sum);

    while (value > 0) {
        printf("while value: %d\n", value);
        value--;
    }

    do {
        printf("countdown: %d\n", countdown);
        countdown--;
    } while (countdown > 0);

    return 0;
}

