# Complete Question Bank

Attempt questions without reading the answer guide. For code-tracing questions, first predict the result, then compile only programs that do not contain undefined behavior. For debugging questions, explain the violated rule before writing a correction.

## Part 1: Foundations and compilation

1. Define a C implementation.
2. Distinguish source file, translation unit, object file, library, and executable.
3. Describe preprocessing, compilation, assembly, and linking.
4. What is separate compilation and why does it reduce build time?
5. Distinguish compiler, assembler, linker, loader, and interpreter.
6. Compare system software and application software with three examples each.
7. Why do C standards exist?
8. Define defined, implementation-defined, unspecified, and undefined behavior.
9. What does `-std=c17` request?
10. Why should warnings be treated seriously?

## Part 2: Types, storage and operators

11. Why does the standard not fix `int` at exactly 32 bits?
12. Compare signed and unsigned overflow.
13. What are integer promotions?
14. Why can `5 / 2` and `5.0 / 2` differ?
15. Distinguish scope, storage duration, and linkage.
16. Explain `auto`, `static`, `extern`, and `register`.
17. What initialization do static-storage objects receive?
18. Why can reading an uninitialized automatic variable be invalid?
19. Explain header guards.
20. Compare a macro constant, enumeration constant, and const-qualified object.
21. Why must function-like macro parameters be parenthesized?
22. Why is `SQUARE(i++)` dangerous even with parentheses?
23. Distinguish precedence, associativity, and evaluation order.
24. Explain short-circuit evaluation with a pointer example.
25. Write an expression that extracts bit three from an unsigned integer.

## Part 3: Control flow

26. When is an else-if ladder preferable to switch?
27. Explain switch fallthrough.
28. Compare for, while, and do-while.
29. What does continue do in a for loop?
30. What does break do in nested loops?
31. Compare break, return, and exit.
32. Why can failed `scanf` input create an infinite loop?
33. List structured alternatives to goto.
34. Give one disciplined resource-cleanup use for goto.
35. Write a loop invariant for summing elements from index zero to index `n - 1`.

## Part 4: Functions

36. Distinguish function declaration and definition.
37. Explain why prototypes improve diagnostics.
38. Distinguish parameter and argument.
39. Prove with an example that C passes arguments by value.
40. How do pointers create reference-like behavior?
41. Why must array length be passed separately to a function?
42. Explain `argc`, `argv`, and the null pointer after the final argument.
43. Why is `strtol` better than `atoi` for validation?
44. What makes recursion terminate?
45. Why is returning a pointer to an automatic local invalid?

## Part 5: Arrays and strings

46. Define array length and capacity.
47. What are the valid indices of an array containing `n` elements?
48. Why cannot arrays be assigned as complete objects?
49. Explain `sizeof array / sizeof array[0]` and its scope limitation.
50. Define a C string and explain its terminator.
51. Compare a modifiable character array and a string literal pointer.
52. Why is `gets` impossible to use safely?
53. Explain newline handling with `fgets`.
54. State the preconditions of `strcpy`.
55. What exactly does `strcmp` guarantee about its result?
56. Why is `strrev` not portable?
57. Compare getchar, getc, and fgetc.
58. Why must character input be stored in `int` when EOF matters?
59. Why are `getch`, `putch`, and `conio.h` not suitable for portable code?
60. Explain row-major storage for a two-dimensional array.

## Part 6: Pointers and dynamic memory

61. Define pointer, pointee, address, dereference, and null pointer.
62. Why is non-null not sufficient to prove pointer validity?
63. Explain valid pointer arithmetic boundaries.
64. Show the equivalence between array indexing and pointer arithmetic.
65. What is a double pointer and when is it useful?
66. Distinguish an array of pointers from a pointer to an array.
67. Explain a function pointer declaration from the identifier outward.
68. What storage can a function safely return a pointer to?
69. Explain the structure arrow operator.
70. Compare pointer to const, const pointer, and const pointer to const.
71. Compare malloc and calloc.
72. Why is a temporary pointer required with realloc?
73. Define ownership and borrowing.
74. Define memory leak, use after free, double free, and dangling pointer.
75. Why can allocation-size multiplication overflow?

## Part 7: Records and files

76. Compare structure and union storage.
77. Explain structure padding.
78. Why is raw structure serialization not portable?
79. What problem does a tagged union solve?
80. Why use an enum instead of unexplained integers?
81. Explain every standard text file mode.
82. What does fopen return on failure?
83. Why should fclose be checked for output files?
84. Explain why `while (!feof(file))` is wrong.
85. How do feof and ferror distinguish failure reasons?
86. Compare fgetc, fgets, fputc, and fprintf.
87. Design a safe replacement workflow using a temporary file.
88. Explain restrictions when switching direction on an update stream.

## Part 8: Programming exercises

89. Build a validated grade calculator with statistics for a class.
90. Build a menu-driven number utility for prime, palindrome, factorial, and GCD operations.
91. Implement selection, insertion, and bubble sort, then compare their operation counts.
92. Implement a capacity-aware portable string toolkit.
93. Implement matrix addition, transpose, and multiplication.
94. Implement a command-line calculator with overflow detection.
95. Implement a resizable integer vector.
96. Implement a dynamically allocated list of student structures.
97. Implement a tagged-union expression value.
98. Implement a text-file analyzer with a frequency table.
99. Implement record add, list, find, update, and delete operations using a safe temporary-file process.
100. Split one project into at least three source files and two headers with a build script.

## Part 9: Debugging exercises

### Exercise 101

```c
int values[5];
for (int i = 0; i <= 5; i++) {
    values[i] = i;
}
```

Identify the invalid access and correct the loop invariant.

### Exercise 102

```c
char *text = "hello";
text[0] = 'H';
```

Explain why this is invalid and provide two valid alternatives for different intentions.

### Exercise 103

```c
int *create_value(void)
{
    int value = 10;
    return &value;
}
```

Explain the lifetime problem and propose caller-owned, static, and dynamic alternatives.

### Exercise 104

```c
int *values = malloc(10 * sizeof(*values));
values = realloc(values, 20 * sizeof(*values));
```

Explain the failure-path leak and correct it.

### Exercise 105

```c
while (!feof(file)) {
    fgets(line, sizeof(line), file);
    puts(line);
}
```

Explain stale-data processing and write the correct loop.

### Exercise 106

```c
#define SQUARE(x) x * x
int result = SQUARE(2 + 3);
```

Show the expansion, result, parenthesized repair, and remaining side-effect limitation.

### Exercise 107

```c
if (choice = 2) {
    puts("selected");
}
```

Explain the value and side effect of the condition.

### Exercise 108

```c
char character;
while ((character = fgetc(file)) != EOF) {
    putchar(character);
}
```

Explain why `char` cannot reliably represent every byte and EOF.

## Practice questions

1. Select twenty questions for a one-hour written examination.
2. Select five programming questions for a three-hour practical examination.
3. Write model answers before reading `ANSWER_GUIDE.md`.
4. For every debugging exercise, identify the language rule before proposing code.

