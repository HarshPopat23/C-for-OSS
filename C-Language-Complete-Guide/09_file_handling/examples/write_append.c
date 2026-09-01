#include <stdio.h>

static int write_initial_file(const char *path)
{
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        return 0;
    }
    if (fprintf(file, "101,Aarav,82.50\n102,Diya,91.00\n") < 0) {
        fclose(file);
        return 0;
    }
    return fclose(file) == 0;
}

static int append_record(const char *path)
{
    FILE *file = fopen(path, "a");
    if (file == NULL) {
        return 0;
    }
    if (fprintf(file, "103,Kabir,76.25\n") < 0) {
        fclose(file);
        return 0;
    }
    return fclose(file) == 0;
}

int main(void)
{
    const char *path = "student_records.txt";
    if (!write_initial_file(path) || !append_record(path)) {
        fprintf(stderr, "File operation failed\n");
        return 1;
    }
    printf("Records written to %s\n", path);
    return 0;
}

