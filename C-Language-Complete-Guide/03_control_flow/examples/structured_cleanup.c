#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *input = fopen("input.txt", "r");
    char *buffer = NULL;
    int status = EXIT_FAILURE;

    if (input == NULL) {
        fprintf(stderr, "Could not open input.txt\n");
        goto cleanup;
    }

    buffer = malloc(256);
    if (buffer == NULL) {
        fprintf(stderr, "Could not allocate memory\n");
        goto cleanup;
    }

    if (fgets(buffer, 256, input) != NULL) {
        printf("First line: %s", buffer);
    }
    status = EXIT_SUCCESS;

cleanup:
    free(buffer);
    if (input != NULL) {
        fclose(input);
    }
    return status;
}

