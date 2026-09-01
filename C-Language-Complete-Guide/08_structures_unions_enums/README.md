# Structures, Unions and Enumerations

## Structures

A structure groups related values, possibly of different types, into one object.

```c
struct Student {
    int roll_number;
    char name[50];
    double marks;
};
```

Create and initialize an object.

```c
struct Student student = {101, "Diya", 87.5};
```

Access members with the dot operator.

```c
printf("%s\n", student.name);
```

Access through a pointer with the arrow operator.

```c
struct Student *pointer = &student;
pointer->marks = 90.0;
```

## Structure layout and padding

Members appear in declaration order, but an implementation may insert padding between members and after the last member to satisfy alignment. Therefore `sizeof(struct Type)` can exceed the sum of member sizes.

Do not serialize a structure by blindly writing its raw bytes when data must be portable across compilers, architectures, or versions. Padding bytes, endianness, type widths, and representations can differ. Use an explicit text or binary format.

`offsetof` from `<stddef.h>` reports a member offset for inspection.

## Structure initialization and assignment

Designated initializers improve clarity.

```c
struct Student student = {
    .roll_number = 101,
    .name = "Diya",
    .marks = 87.5
};
```

Structures of the same type can be assigned as complete objects. Arrays cannot. Structure assignment copies all members, including embedded arrays as part of the structure value.

Passing a structure by value copies it. Passing a pointer can avoid copying and can permit modification. Use a pointer to const for read-only access.

## Nested structures and arrays of structures

A structure may contain another structure, an array, or pointers. Arrays of structures are useful for fixed-capacity collections of records.

```c
struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    int roll_number;
    struct Date admission_date;
};
```

## Self-referential structures

A structure cannot contain a complete object of its own type because that would require infinite size. It can contain a pointer to its own type.

```c
struct Node {
    int value;
    struct Node *next;
};
```

This supports linked lists and trees. Memory ownership rules must specify who allocates and frees nodes.

## Unions

A union provides multiple member views over shared storage. Its size is sufficient for its largest member plus any required alignment.

```c
union Number {
    int integer;
    double real;
};
```

Only one member value should normally be treated as active at a time. Writing `integer` and then reading `real` is not a portable numeric conversion. Use an explicit tag to record which member is valid.

Unions are useful when an object can hold one of several alternatives and memory must be shared. They are also used in low-level representations, but portability rules require care.

## Tagged union

Combine an enumeration tag with a union.

```c
enum ValueKind {
    VALUE_INTEGER,
    VALUE_REAL
};

struct Value {
    enum ValueKind kind;
    union {
        int integer;
        double real;
    } data;
};
```

Code checks `kind` before reading the corresponding union member. This models a safe variant-like value.

## Enumerations

An enumeration defines named integer constants.

```c
enum Status {
    STATUS_PENDING,
    STATUS_ACTIVE,
    STATUS_CLOSED
};
```

By default values begin at zero and increase by one, but explicit values are allowed. Enumeration names improve readability compared with unexplained numeric constants.

An enum variable can still hold values outside the listed enumerators depending on integer conversions and implementation rules. Validate external input before converting it into application state.

## Typedef

`typedef` creates a type alias.

```c
typedef struct Student Student;
```

Then `Student` can be used without writing `struct`. Keeping the `struct` tag visible can also make record types obvious. Both styles are valid; choose one consistently.

## Choosing a model

Use a structure when all members conceptually exist together. Use a union when alternatives share storage and only one is active. Use an enumeration for a closed set of named integer states. Combine an enum and union for alternatives with an explicit active tag.

## Practice questions

1. Define a student structure with roll number, name, semester, and marks.
2. Use designated initialization and print every member.
3. Create an array of students and find the highest marks.
4. Pass a structure by value and by pointer. Explain the behavioral and cost differences.
5. Inspect member offsets and total size for structures with different member orders.
6. Explain structure padding and why raw-byte file storage is not portable.
7. Build nested structures for a student and admission date.
8. Explain why a structure can contain a pointer to itself but not a complete instance of itself.
9. Compare structure and union memory behavior.
10. Build a tagged union supporting integer, real, and short text values.
11. Define an enum for menu actions and use it in a switch.
12. Explain what `typedef` changes and what it does not change.

