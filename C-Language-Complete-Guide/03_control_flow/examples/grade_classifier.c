#include <stdio.h>

int main(void)
{
    int marks;

    printf("Enter marks from 0 to 100: ");
    if (scanf("%d", &marks) != 1) {
        fprintf(stderr, "Invalid numeric input\n");
        return 1;
    }
    if (marks < 0 || marks > 100) {
        fprintf(stderr, "Marks are outside the valid range\n");
        return 1;
    }

    if (marks >= 90) {
        printf("Grade A\n");
    } else if (marks >= 75) {
        printf("Grade B\n");
    } else if (marks >= 60) {
        printf("Grade C\n");
    } else if (marks >= 40) {
        printf("Grade D\n");
    } else {
        printf("Grade F\n");
    }
    return 0;
}

