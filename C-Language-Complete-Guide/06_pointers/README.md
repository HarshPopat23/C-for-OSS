# Pointers

Pointers are typed values that can represent addresses of objects or functions. They enable indirect access, array traversal, dynamic memory, output parameters, callbacks, data structures, and interaction with low-level interfaces.

## Declaration and initialization

```c
int value = 42;
int *pointer = &value;
```

`&value` produces the address of `value`. `pointer` stores that address. `*pointer` accesses the pointed-to integer. In a declaration, `*` helps declare a pointer type. In an expression, unary `*` dereferences a pointer.

Declare one pointer per declaration when clarity matters.

```c
int *first;
int second;
```

Only `first` is a pointer. The `*` binds to the declarator, not to the base type text.

## Null, valid and invalid pointers

A null pointer intentionally points to no object or function.

```c
int *pointer = NULL;
```

Test before dereferencing when null is possible. A non-null pointer is not automatically valid. It can be uninitialized, dangling after an object's lifetime ends, point outside an array, or have an incompatible type.

Dereferencing an invalid pointer produces undefined behavior.

## Pointer to int

An `int *` points to an integer. It can read or modify the integer when the pointed object permits modification.

```c
int score = 70;
int *score_pointer = &score;
*score_pointer += 5;
```

After the operation, `score` is 75.

## Pointer to char

A `char *` can point to a character or the first character of a modifiable character array. A `const char *` is commonly used to read a string without modifying it.

```c
char text[] = "hello";
char *cursor = text;
while (*cursor != '\0') {
    cursor++;
}
```

String literals should be referenced through `const char *` because modifying a string literal is undefined behavior.

## Pointer arithmetic

If `pointer` points to an array element, `pointer + 1` points to the next element, not the next byte. The address changes by `sizeof(*pointer)` bytes.

Valid pointer arithmetic stays within one array object or one position past its end. A one-past pointer can be used for comparison but must not be dereferenced. Subtracting two pointers is defined only when they point into the same array, and the result has type `ptrdiff_t`.

Array indexing is defined in terms of pointer arithmetic: `array[index]` is equivalent to `*(array + index)`.

## Double pointer

A double pointer points to a pointer.

```c
int value = 10;
int *pointer = &value;
int **double_pointer = &pointer;
```

`**double_pointer` accesses `value`. Double pointers are used to modify a caller's pointer, represent arrays of string pointers, manage dynamically allocated structures, and implement linked data structures.

To let a function allocate memory and update the caller's pointer, pass a pointer to that pointer.

## Array of pointers

```c
const char *names[] = {"Aarav", "Diya", "Kabir"};
```

`names` is an array whose elements are pointers to constant characters. The strings can have different lengths and need not be adjacent. The array elements themselves can be reordered if the array is not const.

## Pointer to an array

```c
int matrix[3][4];
int (*row_pointer)[4] = matrix;
```

`row_pointer` points to an array of four integers. Parentheses are required because `int *row_pointer[4]` would declare an array of four integer pointers.

Incrementing `row_pointer` advances by one complete row. `row_pointer[row][column]` accesses an element.

## Function pointer

A function pointer stores the address of a compatible function.

```c
int add(int a, int b);
int (*operation)(int, int) = add;
int result = operation(2, 3);
```

Function pointers support callbacks, dispatch tables, sorting comparators, and configurable algorithms. Calling through an incompatible function pointer type is undefined behavior.

Read `int (*operation)(int, int)` from the identifier outward: `operation` is a pointer to a function taking two integers and returning an integer.

## Function returning a pointer

```c
int *find_value(int values[], size_t length, int target);
```

This declares a function returning `int *`. It can return the address of a matching array element or `NULL`. The returned pointer remains valid only while the original array remains alive.

A function must not return a pointer to its automatic local variable. It may return a pointer to caller-owned storage, static storage, string literal storage with `const`, or dynamically allocated storage whose ownership is clear.

## Pointer to structure

If `student_pointer` points to a structure, these are equivalent.

```c
(*student_pointer).marks
student_pointer->marks
```

The arrow operator is clearer. Structure pointers avoid copying large structures and enable dynamic linked structures. Use `const struct Student *` when a function only reads the structure.

## Void pointer

`void *` can hold a pointer to any object type and converts to and from object pointers in C. It cannot be dereferenced directly because the pointed type and size are unknown. Convert it to the correct pointer type first.

`malloc` returns `void *`. In C, do not cast its result; including `<stdlib.h>` provides the correct declaration and implicit object-pointer conversion.

## Const with pointers

```c
const int *pointer_to_const;
int *const const_pointer = &value;
const int *const const_pointer_to_const = &value;
```

`pointer_to_const` can point elsewhere but cannot modify the integer through that pointer. `const_pointer` cannot point elsewhere but can modify its integer. The last declaration permits neither change through that identifier.

## Pointer safety checklist

1. Initialize every pointer.
2. Use `NULL` to represent no target.
3. Dereference only a pointer known to refer to a live object or function.
4. Stay within array bounds during pointer arithmetic.
5. Match pointer types and function signatures.
6. Respect `const`.
7. Do not return addresses of automatic local variables.
8. After `free`, do not dereference or compare the pointer as an object address; set the owning variable to `NULL` when useful.
9. Document who owns dynamically allocated memory.
10. Never assume a pointer and integer have the same representation.

## Practice questions

1. Draw the objects and addresses for an integer, pointer, and double pointer.
2. Explain the two meanings of `*` and the meaning of `&`.
3. Write a function that increments an integer through a pointer.
4. Traverse a numeric array using pointers without index notation.
5. Explain the only valid range for a pointer moving through an array.
6. Allocate an integer array through a function receiving `int **`.
7. Build an array of pointers to month names and print it.
8. Explain the declaration difference between `int *a[5]` and `int (*a)[5]`.
9. Write a function pointer dispatch table for four arithmetic operations.
10. Write a function returning a pointer to the first matching array element.
11. Explain why returning `&local_variable` is invalid.
12. Write a function that accepts a pointer to a structure and updates one member.
13. Explain why `void *` cannot be dereferenced directly.
14. Interpret three declarations involving pointer constness.
15. Identify null, wild, dangling, one-past, and valid pointers in sample code of your own.

