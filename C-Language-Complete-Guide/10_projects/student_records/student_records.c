#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORD_FILE "student_records.txt"
#define NAME_CAPACITY 80
#define LINE_CAPACITY 256

struct Student {
    int roll;
    char name[NAME_CAPACITY];
    double marks;
};

static int read_line(const char *prompt, char buffer[], size_t capacity)
{
    printf("%s", prompt);
    if (fgets(buffer, capacity, stdin) == NULL) {
        return 0;
    }
    size_t newline = strcspn(buffer, "\n");
    if (buffer[newline] == '\n') {
        buffer[newline] = '\0';
        return 1;
    }
    int character;
    while ((character = getchar()) != '\n' && character != EOF) {
    }
    return 0;
}

static int parse_int(const char *text, int *result)
{
    char *end;
    errno = 0;
    long value = strtol(text, &end, 10);
    if (errno != 0 || end == text || *end != '\0' || value < 1 || value > 1000000000L) {
        return 0;
    }
    *result = (int) value;
    return 1;
}

static int parse_double(const char *text, double *result)
{
    char *end;
    errno = 0;
    double value = strtod(text, &end);
    if (errno != 0 || end == text || *end != '\0' || !isfinite(value) ||
        value < 0.0 || value > 100.0) {
        return 0;
    }
    *result = value;
    return 1;
}

static int parse_record(char line[], struct Student *student)
{
    char *first = strchr(line, '|');
    char *last = strrchr(line, '|');
    if (first == NULL || last == first || strchr(first + 1, '|') != last) {
        return 0;
    }
    *first = '\0';
    *last = '\0';
    if (!parse_int(line, &student->roll) || !parse_double(last + 1, &student->marks)) {
        return 0;
    }
    if (strlen(first + 1) >= sizeof(student->name)) {
        return 0;
    }
    strcpy(student->name, first + 1);
    return 1;
}

static int add_record(void)
{
    struct Student student;
    char input[LINE_CAPACITY];

    if (!read_line("Roll number: ", input, sizeof(input)) || !parse_int(input, &student.roll)) {
        puts("Invalid roll number");
        return 0;
    }
    if (!read_line("Name: ", student.name, sizeof(student.name)) ||
        student.name[0] == '\0' || strchr(student.name, '|') != NULL) {
        puts("Invalid name");
        return 0;
    }
    if (!read_line("Marks from 0 to 100: ", input, sizeof(input)) ||
        !parse_double(input, &student.marks)) {
        puts("Invalid marks");
        return 0;
    }

    FILE *file = fopen(RECORD_FILE, "a");
    if (file == NULL) {
        perror("Could not open record file");
        return 0;
    }
    int ok = fprintf(file, "%d|%s|%.2f\n", student.roll, student.name, student.marks) >= 0;
    if (fclose(file) != 0) {
        ok = 0;
    }
    puts(ok ? "Record added" : "Could not save record");
    return ok;
}

static int list_or_find_records(int wanted_roll)
{
    FILE *file = fopen(RECORD_FILE, "r");
    if (file == NULL) {
        puts("No record file exists yet");
        return 0;
    }

    char line[LINE_CAPACITY];
    int found = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        struct Student student;
        if (!parse_record(line, &student)) {
            fprintf(stderr, "Skipped malformed record\n");
            continue;
        }
        if (wanted_roll == 0 || student.roll == wanted_roll) {
            printf("Roll: %d, Name: %s, Marks: %.2f\n", student.roll, student.name, student.marks);
            found = 1;
        }
    }
    if (ferror(file)) {
        fprintf(stderr, "Read error\n");
    }
    fclose(file);
    if (!found) {
        puts("No matching record");
    }
    return found;
}

int main(void)
{
    char input[LINE_CAPACITY];

    for (;;) {
        puts("\n1 Add record\n2 List records\n3 Find by roll\n4 Exit");
        if (!read_line("Choice: ", input, sizeof(input))) {
            puts("Input ended");
            return 0;
        }
        int choice;
        if (!parse_int(input, &choice)) {
            puts("Invalid choice");
            continue;
        }
        switch (choice) {
        case 1:
            add_record();
            break;
        case 2:
            list_or_find_records(0);
            break;
        case 3: {
            int roll;
            if (read_line("Roll to find: ", input, sizeof(input)) && parse_int(input, &roll)) {
                list_or_find_records(roll);
            } else {
                puts("Invalid roll number");
            }
            break;
        }
        case 4:
            return 0;
        default:
            puts("Unknown choice");
            break;
        }
    }
}
