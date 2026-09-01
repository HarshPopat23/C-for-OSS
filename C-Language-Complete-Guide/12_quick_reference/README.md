# C Quick Reference

This chapter is for revision after learning the concepts. Tables do not replace the detailed explanations in earlier folders.

## Standard compilation

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic source.c -o program
```

Debug build with sanitizers:

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined source.c -o program
```

## Common types and printf conversions

| C type | printf conversion |
| --- | --- |
| `char` as character | `%c` |
| `int` | `%d` |
| `unsigned int` | `%u` |
| `long` | `%ld` |
| `unsigned long` | `%lu` |
| `long long` | `%lld` |
| `unsigned long long` | `%llu` |
| `double` | `%f`, `%e`, or `%g` |
| `long double` | `%Lf`, `%Le`, or `%Lg` |
| string | `%s` |
| pointer after conversion to `void *` | `%p` |
| `size_t` | `%zu` |
| `ptrdiff_t` | `%td` |

For scanf, `float *` uses `%f` and `double *` uses `%lf`. Always match the destination type and use field widths for strings.

## Escape sequences

| Sequence | Meaning |
| --- | --- |
| `\n` | Newline |
| `\t` | Horizontal tab |
| `\\` | Backslash |
| `\"` | Double quote |
| `\'` | Single quote |
| `\0` | Null character when followed appropriately |

## Operator precedence from high to low

| Level | Operators | Associativity |
| --- | --- | --- |
| Postfix | `()`, `[]`, `.`, `->`, postfix `++`, postfix `--` | Left to right |
| Unary | prefix `++`, prefix `--`, unary `+`, unary `-`, `!`, `~`, `*`, `&`, `sizeof`, cast | Right to left |
| Multiplicative | `*`, `/`, `%` | Left to right |
| Additive | `+`, `-` | Left to right |
| Shift | `<<`, `>>` | Left to right |
| Relational | `<`, `<=`, `>`, `>=` | Left to right |
| Equality | `==`, `!=` | Left to right |
| Bitwise AND | `&` | Left to right |
| Bitwise XOR | `^` | Left to right |
| Bitwise OR | `|` | Left to right |
| Logical AND | `&&` | Left to right |
| Logical OR | `||` | Left to right |
| Conditional | `?:` | Right to left |
| Assignment | `=`, compound assignments | Right to left |
| Comma | `,` | Left to right |

Precedence does not normally specify operand evaluation order. Use parentheses for communication and avoid unsequenced side effects.

## Storage-class summary

| Specifier | Typical scope | Duration or role | Linkage effect |
| --- | --- | --- | --- |
| `auto` | Block | Automatic | None |
| `register` | Block | Automatic with historical optimization suggestion | None |
| `static` local | Block | Static | None |
| `static` file entity | File | Static for objects | Internal linkage |
| `extern` | File or block | Declares an entity defined elsewhere | Usually external linkage |

## String and character functions

| Function | Header | Purpose | Key rule |
| --- | --- | --- | --- |
| `strlen` | `string.h` | String length | Input must be terminated |
| `strcpy` | `string.h` | Copy string | Destination must fit |
| `strcmp` | `string.h` | Compare strings | Test sign, not exact nonzero value |
| `fgets` | `stdio.h` | Bounded line or chunk input | May retain newline |
| `puts` | `stdio.h` | Write string and newline | Returns EOF on failure |
| `getchar` | `stdio.h` | Read from stdin | Store result in int |
| `getc`, `fgetc` | `stdio.h` | Read from stream | Store result in int |
| `putchar` | `stdio.h` | Write to stdout | Check EOF on failure-sensitive paths |
| `putc`, `fputc` | `stdio.h` | Write to stream | Check EOF |

`gets` is removed and unsafe. `strrev`, `getch`, `putch`, and `conio.h` are non-standard.

## Dynamic memory

| Function | Purpose | Initial contents |
| --- | --- | --- |
| `malloc(bytes)` | Allocate bytes | Indeterminate |
| `calloc(count, size)` | Allocate array storage | All bits zero |
| `realloc(pointer, bytes)` | Resize allocation | Old prefix preserved on success |
| `free(pointer)` | Release allocation | Pointer aliases become dangling |

Check failure, arithmetic overflow, bounds, ownership, and exactly-once release.

## File modes

| Mode | Read | Write | Append | Must exist | Truncates |
| --- | --- | --- | --- | --- | --- |
| `r` | Yes | No | No | Yes | No |
| `w` | No | Yes | No | No | Yes |
| `a` | No | Yes | Yes | No | No |
| `r+` | Yes | Yes | No | Yes | No |
| `w+` | Yes | Yes | No | No | Yes |
| `a+` | Yes | Yes | Yes | No | No |

## Final safety review

Before considering a program complete, check these points.

1. Every input result is checked.
2. Every array access is within logical length and capacity.
3. Every string is terminated and every destination has capacity.
4. Every pointer is initialized and refers to a live object before dereference.
5. Every allocation has one owner and one eventual free.
6. Every file-open result is checked and every open stream is closed.
7. Input loops are controlled by input-operation results.
8. Arithmetic avoids division by zero and relevant overflow.
9. Functions do not return addresses of expired objects.
10. Strict compiler warnings are enabled and reviewed.

## Practice questions

1. Recreate the precedence table from memory, then explain why memorization is not enough.
2. Select the correct conversion for ten type examples.
3. Write a checklist specific to string-processing programs.
4. Write a checklist specific to dynamic-memory programs.
5. Explain every item in the final safety review to another student.

