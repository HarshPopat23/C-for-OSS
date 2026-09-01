#include <stddef.h>
#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    int roll_number;
    char name[40];
    struct Date admission_date;
    double marks;
};

static void print_student(const struct Student *student)
{
    printf("roll: %d\n", student->roll_number);
    printf("name: %s\n", student->name);
    printf("admission: %02d-%02d-%04d\n",
           student->admission_date.day,
           student->admission_date.month,
           student->admission_date.year);
    printf("marks: %.2f\n", student->marks);
}

int main(void)
{
    struct Student student = {
        .roll_number = 101,
        .name = "Diya",
        .admission_date = {15, 8, 2026},
        .marks = 87.5
    };

    print_student(&student);
    printf("structure size: %zu\n", sizeof(student));
    printf("marks offset: %zu\n", offsetof(struct Student, marks));
    return 0;
}

