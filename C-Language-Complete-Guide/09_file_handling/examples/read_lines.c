#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open %s: %s\n", argv[1], strerror(errno));
        return 1;
    }

    char line[256];
    size_t line_number = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;
        printf("%4zu: %s", line_number, line);
    }

    int status = 0;
    if (ferror(file)) {
        fprintf(stderr, "Input error\n");
        status = 1;
    } else if (feof(file)) {
        printf("Reached end of file after %zu chunks\n", line_number);
    }

    if (fclose(file) == EOF) {
        fprintf(stderr, "Close failed\n");
        status = 1;
    }
    return status;
}

