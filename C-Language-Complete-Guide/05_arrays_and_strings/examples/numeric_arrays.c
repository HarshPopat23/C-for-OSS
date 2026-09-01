#include <stddef.h>
#include <stdio.h>

static void reverse(int values[], size_t length)
{
    for (size_t left = 0, right = length; left < right && left < --right; left++) {
        int temporary = values[left];
        values[left] = values[right];
        values[right] = temporary;
    }
}

int main(void)
{
    int values[] = {12, 5, 9, 21, -4, 9};
    const size_t length = sizeof(values) / sizeof(values[0]);
    long long sum = 0;
    int minimum = values[0];
    int maximum = values[0];

    for (size_t index = 0; index < length; index++) {
        sum += values[index];
        if (values[index] < minimum) {
            minimum = values[index];
        }
        if (values[index] > maximum) {
            maximum = values[index];
        }
    }

    printf("sum: %lld, average: %.2f, minimum: %d, maximum: %d\n",
           sum, (double) sum / (double) length, minimum, maximum);

    reverse(values, length);
    printf("reversed:");
    for (size_t index = 0; index < length; index++) {
        printf(" %d", values[index]);
    }
    putchar('\n');
    return 0;
}

