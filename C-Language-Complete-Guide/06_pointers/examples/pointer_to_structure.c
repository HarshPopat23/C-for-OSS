#include <stdio.h>

struct Student {
    int roll_number;
    char name[40];
    double marks;
};

static void add_bonus(struct Student *student, double bonus)
{
    if (student != NULL) {
        student->marks += bonus;
    }
}

static void print_student(const struct Student *student)
{
    if (student != NULL) {
        printf("%d, %s, %.2f\n", student->roll_number, student->name, student->marks);
    }
}

int main(void)
{
    struct Student student = {101, "Aarav", 82.5};
    add_bonus(&student, 2.0);
    print_student(&student);
    return 0;
}

