#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[1], "rb");
    if (source == NULL) {
        fprintf(stderr, "Could not open %s: %s\n", argv[1], strerror(errno));
        return 1;
    }

    FILE *destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        fprintf(stderr, "Could not open %s: %s\n", argv[2], strerror(errno));
        fclose(source);
        return 1;
    }

    int status = 0;
    int character;
    while ((character = fgetc(source)) != EOF) {
        if (fputc(character, destination) == EOF) {
            fprintf(stderr, "Write failed\n");
            status = 1;
            break;
        }
    }
    if (ferror(source)) {
        fprintf(stderr, "Read failed\n");
        status = 1;
    }
    if (fclose(source) == EOF) {
        fprintf(stderr, "Could not close source\n");
        status = 1;
    }
    if (fclose(destination) == EOF) {
        fprintf(stderr, "Could not finish destination\n");
        status = 1;
    }
    return status;
}

