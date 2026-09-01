#include <stdio.h>

int main(void)
{
    char name[50];
    int year;

    printf("Enter your first name: ");
    if (scanf("%49s", name) != 1) {
        fprintf(stderr, "Could not read the name\n");
        return 1;
    }

    printf("Enter your graduation year: ");
    if (scanf("%d", &year) != 1) {
        fprintf(stderr, "Could not read the year\n");
        return 1;
    }

    printf("%s plans to graduate in %d.\n", name, year);
    return 0;
}

