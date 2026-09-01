#include <stdio.h>

int main(void)
{
    for (int row = 1; row <= 5; row++) {
        for (int column = 1; column <= 5; column++) {
            if (row == column) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        putchar('\n');
    }

    printf("Odd values below 20, stopping after 15:\n");
    for (int value = 1; value < 20; value++) {
        if (value % 2 == 0) {
            continue;
        }
        if (value > 15) {
            break;
        }
        printf("%d ", value);
    }
    putchar('\n');
    return 0;
}

