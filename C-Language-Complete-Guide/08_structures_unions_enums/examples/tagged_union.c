#include <stdio.h>

enum ValueKind {
    VALUE_INTEGER,
    VALUE_REAL,
    VALUE_TEXT
};

struct Value {
    enum ValueKind kind;
    union {
        int integer;
        double real;
        char text[32];
    } data;
};

static void print_value(const struct Value *value)
{
    switch (value->kind) {
    case VALUE_INTEGER:
        printf("integer: %d\n", value->data.integer);
        break;
    case VALUE_REAL:
        printf("real: %.2f\n", value->data.real);
        break;
    case VALUE_TEXT:
        printf("text: %s\n", value->data.text);
        break;
    default:
        puts("invalid value kind");
        break;
    }
}

int main(void)
{
    struct Value values[] = {
        {.kind = VALUE_INTEGER, .data.integer = 42},
        {.kind = VALUE_REAL, .data.real = 3.5},
        {.kind = VALUE_TEXT, .data.text = "C language"}
    };
    size_t count = sizeof(values) / sizeof(values[0]);

    for (size_t index = 0; index < count; index++) {
        print_value(&values[index]);
    }
    return 0;
}

