# Arrays and Strings

## One-dimensional arrays

An array is a fixed-size sequence of elements of one type stored contiguously. If an array has `n` elements, valid indices are `0` through `n - 1`.

```c
int marks[5] = {82, 75, 91, 68, 88};
```

`marks[0]` is the first element. C performs no automatic bounds checking. Accessing before the first element or after the last element produces undefined behavior.

The number of elements can be computed only where the array itself is available.

```c
size_t length = sizeof(marks) / sizeof(marks[0]);
```

Inside a function parameter, the array declaration is adjusted to a pointer, so this expression no longer gives the original length. Pass the length explicitly.

## Initialization

If fewer initializers are supplied, remaining elements are initialized to zero.

```c
int values[5] = {1, 2};
```

This creates `{1, 2, 0, 0, 0}`. `int values[5] = {0};` initializes all elements to zero. An automatic array without an initializer contains indeterminate values.

Arrays cannot be assigned as complete objects after declaration. Copy elements individually or use a suitable library operation with correct byte counts.

## Numeric array operations

Common operations include traversal, sum, average, minimum, maximum, search, insertion into available capacity, deletion by shifting, sorting, and copying. Always distinguish logical length from allocated capacity.

For example, an array with capacity 100 may currently contain 35 meaningful elements. An insertion must check that length is less than capacity.

## Character arrays and strings

A C string is a character array containing a terminating null character `\0`. The null terminator is part of the representation but not part of the logical text length.

```c
char word[] = "C language";
```

The compiler allocates enough elements for the visible characters plus `\0`.

These declarations differ.

```c
char editable[] = "hello";
const char *literal = "hello";
```

`editable` is a modifiable array initialized from a string literal. `literal` points to a string literal that must not be modified. Attempting to modify a literal produces undefined behavior.

## Safe string input

`scanf("%s", text)` stops at whitespace and must include a field width to prevent overflow. For line input, prefer `fgets`.

```c
char line[100];
if (fgets(line, sizeof(line), stdin) != NULL) {
    line[strcspn(line, "\n")] = '\0';
}
```

`fgets` reads at most one less than the given size and writes a null terminator on success. If a newline fits, it is retained, so programs often remove it. If the input line is longer than the buffer, the remainder stays unread and must be handled.

## Why gets must not be used

`gets` has no buffer-size argument and therefore cannot prevent overflow. It was removed from the C standard in C11. There is no safe way to use it. Use `fgets`.

Code that teaches `gets` as a normal option is outdated and dangerous.

## Standard string functions

Include `<string.h>`.

### strlen

`strlen(text)` returns the number of characters before `\0` as `size_t`. The input must point to a valid null-terminated string.

### strcpy

`strcpy(destination, source)` copies the source including `\0`. The destination must be large enough and the arrays must not overlap. Because the function does not receive destination capacity, validate size before calling or use a capacity-aware design.

### strcmp

`strcmp(left, right)` returns a value less than zero, equal to zero, or greater than zero based on lexicographic comparison. Do not assume it returns exactly `-1` or `1`. String equality is `strcmp(a, b) == 0`; `a == b` compares pointer values, not text.

### strcat

Although not explicitly listed in the syllabus, concatenation is common. `strcat(destination, source)` appends source, but destination must have enough unused capacity. Track capacity before appending.

### strrev

`strrev` is not an ISO C function. Some compilers provide it as an extension. Portable programs implement reversal with a loop or a project function, as shown in `string_toolkit.c`.

## User-defined string functions

Writing your own versions of length, copy, comparison, and reversal teaches traversal and termination rules. Production code should generally use the standard library for standard operations, with correct capacity validation.

Every custom copy function should accept destination capacity or have a clearly enforced precondition. A safer teaching interface is:

```c
int string_copy(char destination[], size_t capacity, const char source[]);
```

It returns failure if the source does not fit.

## Character input and output functions

### getchar and putchar

`getchar()` reads one character from `stdin` and returns it as an `int`, or returns `EOF`. Store the result in `int`, not `char`, so every unsigned-char value remains distinguishable from `EOF`.

`putchar(character)` writes one character to `stdout` and returns the written character converted to unsigned char, or `EOF` on failure.

### getc, fgetc, putc and fputc

`getc(stream)` and `fgetc(stream)` read one character from a stream. `getc` may be implemented as a macro; `fgetc` is a function interface. Their observable purpose is otherwise similar.

`putc(character, stream)` and `fputc(character, stream)` write one character. File usage appears in the file-handling chapter.

### puts

`puts(text)` writes a string followed by a newline. It returns a non-negative value on success or `EOF` on failure.

### getch and putch

`getch`, `putch`, and `<conio.h>` are not part of ISO C. They are compiler-specific console extensions. Do not require them in portable assignments. Use `getchar` and `putchar`, or use an operating-system-specific terminal library only when the project intentionally accepts that dependency.

## Multidimensional arrays

A two-dimensional array is an array whose elements are arrays.

```c
int matrix[3][4];
```

This contains three arrays, each containing four integers. Elements are stored in row-major order, so all columns of row zero are contiguous before row one.

When passing a multidimensional array, all dimensions except the first must be known so address calculations are possible.

```c
void print_matrix(size_t rows, size_t columns, const int matrix[rows][columns]);
```

Variable-length array parameters are supported in C99 and optional in later standards. A fixed-column alternative can provide broader implementation compatibility.

## Common string and array mistakes

1. Using index equal to array length
2. Forgetting the string null terminator
3. Passing an insufficient destination to `strcpy` or `strcat`
4. Comparing strings with `==`
5. Reading `getchar` into `char` when EOF must be detected
6. Returning a pointer to a local array
7. Using `sizeof` on an array parameter to infer length
8. Modifying a string literal
9. Using `gets`
10. Assuming `strrev`, `getch`, or `putch` is portable

## Practice questions

1. Read ten integers and print their sum, average, minimum, and maximum.
2. Reverse a numeric array in place.
3. Perform linear search and report every matching index.
4. Insert a value at a requested position while respecting capacity.
5. Remove duplicate integers without using another array.
6. Sort an array using selection sort and count comparisons.
7. Explain the difference between array length and capacity.
8. Read a complete line safely and report whether it was truncated.
9. Implement capacity-aware string length, copy, compare, concatenate, and reverse functions.
10. Count vowels, consonants, digits, whitespace, and punctuation in a line.
11. Explain why `strcmp(a, b) == 0` tests equality but `a == b` does not.
12. Explain why `gets` cannot be repaired by careful user behavior.
13. Compare `getchar`, `getc`, and `fgetc`.
14. Explain why an `int` is required to store the result of `getchar`.
15. Add, subtract, and multiply two matrices with validated dimensions.
16. Find the transpose and diagonal sums of a square matrix.
17. Explain row-major storage using element addresses.
18. State which syllabus string or character functions are non-standard or removed.

