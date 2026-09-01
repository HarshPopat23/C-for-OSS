#include <stddef.h>
#include <stdio.h>

static int statistics(
    const int values[], size_t length, int *minimum, int *maximum, double *average
)
{
    if (values == NULL || length == 0 || minimum == NULL || maximum == NULL || average == NULL) {
        return 0;
    }

    int low = values[0];
    int high = values[0];
    long long sum = 0;

    for (size_t index = 0; index < length; index++) {
        if (values[index] < low) {
            low = values[index];
        }
        if (values[index] > high) {
            high = values[index];
        }
        sum += values[index];
    }

    *minimum = low;
    *maximum = high;
    *average = (double) sum / (double) length;
    return 1;
}

int main(void)
{
    int values[] = {14, -3, 25, 8, 11};
    size_t length = sizeof(values) / sizeof(values[0]);
    int minimum;
    int maximum;
    double average;

    if (!statistics(values, length, &minimum, &maximum, &average)) {
        fprintf(stderr, "Could not calculate statistics\n");
        return 1;
    }
    printf("minimum: %d, maximum: %d, average: %.2f\n", minimum, maximum, average);
    return 0;
}

