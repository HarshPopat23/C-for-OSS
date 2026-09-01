#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }

    size_t characters = 0;
    size_t lines = 0;
    size_t words = 0;
    int inside_word = 0;
    int character;

    while ((character = fgetc(file)) != EOF) {
        characters++;
        if (character == '\n') {
            lines++;
        }
        if (isspace((unsigned char) character)) {
            inside_word = 0;
        } else if (!inside_word) {
            inside_word = 1;
            words++;
        }
    }

    if (ferror(file)) {
        fprintf(stderr, "Read failed\n");
        fclose(file);
        return 1;
    }
    if (fclose(file) == EOF) {
        fprintf(stderr, "Close failed\n");
        return 1;
    }

    printf("characters: %zu\nlines: %zu\nwords: %zu\n", characters, lines, words);
    return 0;
}

