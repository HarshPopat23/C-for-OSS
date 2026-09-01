#include <stdio.h>

int main(void)
{
    double left;
    double right;
    char operation;

    printf("Enter an expression such as 12.5 + 3: ");
    if (scanf("%lf %c %lf", &left, &operation, &right) != 3) {
        fprintf(stderr, "Invalid expression\n");
        return 1;
    }

    switch (operation) {
    case '+':
        printf("%.2f\n", left + right);
        break;
    case '-':
        printf("%.2f\n", left - right);
        break;
    case '*':
        printf("%.2f\n", left * right);
        break;
    case '/':
        if (right == 0.0) {
            fprintf(stderr, "Division by zero is not allowed\n");
            return 1;
        }
        printf("%.2f\n", left / right);
        break;
    default:
        fprintf(stderr, "Unsupported operation\n");
        return 1;
    }
    return 0;
}

