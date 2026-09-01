#include <ctype.h>
#include <stdio.h>

struct Statistics {
    size_t bytes;
    size_t lines;
    size_t words;
    size_t uppercase;
    size_t lowercase;
    size_t digits;
    size_t whitespace;
    size_t other;
};

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s text-file\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }

    struct Statistics statistics = {0};
    int inside_word = 0;
    int character;
    while ((character = fgetc(file)) != EOF) {
        unsigned char byte = (unsigned char) character;
        statistics.bytes++;
        if (character == '\n') {
            statistics.lines++;
        }
        if (isspace(byte)) {
            statistics.whitespace++;
            inside_word = 0;
        } else {
            if (!inside_word) {
                statistics.words++;
                inside_word = 1;
            }
            if (isupper(byte)) {
                statistics.uppercase++;
            } else if (islower(byte)) {
                statistics.lowercase++;
            } else if (isdigit(byte)) {
                statistics.digits++;
            } else {
                statistics.other++;
            }
        }
    }

    if (ferror(file)) {
        fprintf(stderr, "Read failed\n");
        fclose(file);
        return 1;
    }
    fclose(file);

    printf("bytes: %zu\n", statistics.bytes);
    printf("lines: %zu\n", statistics.lines);
    printf("words: %zu\n", statistics.words);
    printf("uppercase: %zu\n", statistics.uppercase);
    printf("lowercase: %zu\n", statistics.lowercase);
    printf("digits: %zu\n", statistics.digits);
    printf("whitespace: %zu\n", statistics.whitespace);
    printf("other: %zu\n", statistics.other);
    return 0;
}

