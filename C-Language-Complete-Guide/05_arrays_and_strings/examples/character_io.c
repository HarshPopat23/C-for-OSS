#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int character;
    size_t letters = 0;
    size_t digits = 0;

    puts("Enter text. Send end-of-file to finish.");
    while ((character = getchar()) != EOF) {
        if (isalpha((unsigned char) character)) {
            letters++;
        } else if (isdigit((unsigned char) character)) {
            digits++;
        }
        if (putchar(character) == EOF) {
            fprintf(stderr, "Output failed\n");
            return 1;
        }
    }

    printf("\nletters: %zu, digits: %zu\n", letters, digits);
    return 0;
}

