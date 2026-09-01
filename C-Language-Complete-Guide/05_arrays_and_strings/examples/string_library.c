#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[100];
    char copy[100];

    printf("Enter a line: ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        fprintf(stderr, "Input failed\n");
        return 1;
    }
    line[strcspn(line, "\n")] = '\0';

    if (strlen(line) >= sizeof(copy)) {
        fprintf(stderr, "Text does not fit in destination\n");
        return 1;
    }
    strcpy(copy, line);

    printf("length: %zu\n", strlen(line));
    printf("copy: %s\n", copy);
    printf("comparison with C: %d\n", strcmp(line, "C"));
    puts("puts automatically adds a newline");
    return 0;
}

