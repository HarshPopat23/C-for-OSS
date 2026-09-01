# Data Types, Storage Classes, Preprocessor and Operators

## Objects, variables and types

An object is a region of data storage whose contents can represent a value. A variable is an identifier used to access an object. A type determines the possible values, representation requirements, allowed operations, and interpretation of stored bits.

```c
int count = 10;
const double rate = 2.5;
char grade = 'A';
```

`count` is a modifiable integer object. `rate` is a non-modifiable double object through that identifier because it is qualified with `const`. `grade` stores a character value.

## Fundamental data types

### Integer types

C supplies `char`, `signed char`, `unsigned char`, `short`, `unsigned short`, `int`, `unsigned int`, `long`, `unsigned long`, `long long`, and `unsigned long long`. Exact widths are implementation-defined, but the standard guarantees minimum ranges and an ordering of capacities.

Use `sizeof(type)` to obtain storage size in bytes. A C byte is always the size of `char`, but it is not required to contain exactly eight bits. `CHAR_BIT` from `<limits.h>` gives the number of bits in a byte.

Signed integer overflow is undefined behavior. Unsigned arithmetic wraps modulo one more than the maximum representable value. Do not mix signed and unsigned values carelessly because usual arithmetic conversions can change comparisons.

### Floating types

`float`, `double`, and `long double` represent approximate real values. Many decimal fractions cannot be represented exactly in binary floating point. Compare computed floating values using a tolerance appropriate to the problem rather than expecting exact equality.

### Boolean type

In C17, include `<stdbool.h>` to use `bool`, `true`, and `false`. Internally, `bool` is a convenient spelling based on `_Bool`.

### Void type

`void` represents the absence of a value. A function returning no result uses `void`. `void *` is a generic object pointer that can convert to and from other object pointer types.

### Derived and user-defined types

Arrays, pointers, functions, structures, unions, and enumerations are studied in later chapters. `typedef` creates an alias for an existing type; it does not create a distinct type.

## Literals and format specifiers

Examples of literals include `42`, `42U`, `42L`, `3.14`, `3.14f`, `'A'`, and `"text"`. Literal suffixes influence type.

Common `printf` conversions:

| Type | Conversion |
| --- | --- |
| `int` | `%d` or `%i` |
| `unsigned int` | `%u` |
| `long` | `%ld` |
| `long long` | `%lld` |
| `double` in `printf` | `%f` |
| `char` | `%c` |
| string | `%s` |
| pointer converted to `void *` | `%p` |
| `size_t` | `%zu` |

For `scanf`, the destination type must exactly match the conversion. `double` needs `%lf` in `scanf`, while `float` needs `%f`.

## Scope, storage duration and linkage

These three concepts are related but different.

Scope is the region of source code where an identifier is visible. Storage duration describes how long an object exists. Linkage determines whether declarations in different scopes or translation units refer to the same entity.

### Automatic storage and `auto`

Ordinary block variables have automatic storage duration. They are created when execution enters the block and cease to exist when execution leaves. The `auto` keyword states this default explicitly and is rarely written.

```c
void function(void)
{
    auto int value = 10;
}
```

An uninitialized automatic object has an indeterminate value. Reading it can produce undefined behavior.

### Static storage and `static`

A block-scope `static` object exists for the entire program but is visible only in its block. Its initialization happens once. It retains its value between calls.

A file-scope function or object declared `static` has internal linkage, so its name is private to that translation unit.

Objects with static storage duration are zero-initialized before any explicit initialization.

### External linkage and `extern`

`extern` normally declares an object or function defined elsewhere. It supports communication between translation units. There must be exactly one external definition for an object used by the program.

The example in `examples/extern_demo` uses a header, one source file defining a counter, and another source file using it.

### Suggested access and `register`

`register` requests that an automatic variable be stored for fast access. Modern compilers choose storage better than programmers, so the keyword is largely historical. C does not allow taking the address of an object declared `register`.

## The preprocessor

The preprocessor transforms tokens before compilation.

### File inclusion

```c
#include <stdio.h>
#include "project_header.h"
```

Angle brackets search implementation include locations. Quotes normally search the project location first.

### Object-like macros

```c
#define BUFFER_SIZE 256
```

Prefer typed constants such as `const` variables or enumerators when preprocessing is unnecessary. Macros have no type and obey token substitution rules.

### Function-like macros

```c
#define SQUARE(x) ((x) * (x))
```

Parentheses protect precedence, but `SQUARE(i++)` still evaluates `i++` twice and is invalid logic with undefined behavior. An inline function is safer when possible.

### Conditional compilation

```c
#ifdef DEBUG
    fprintf(stderr, "debug value: %d\n", value);
#endif
```

Other directives include `#if`, `#elif`, `#else`, `#endif`, `#ifndef`, `#undef`, `#error`, and `#pragma`. `#pragma` behavior is implementation-specific.

### Header guards

```c
#ifndef COUNTER_H
#define COUNTER_H

void increment_counter(void);

#endif
```

Guards prevent repeated inclusion from causing duplicate declarations or type definitions.

## Operators

### Main operator groups

| Group | Examples |
| --- | --- |
| Arithmetic | `+`, `-`, `*`, `/`, `%` |
| Relational | `<`, `<=`, `>`, `>=`, `==`, `!=` |
| Logical | `&&`, `||`, `!` |
| Bitwise | `&`, `|`, `^`, `~`, `<<`, `>>` |
| Assignment | `=`, `+=`, `-=`, `*=`, `/=`, `%=` |
| Increment and decrement | `++`, `--` |
| Conditional | `condition ? first : second` |
| Address and indirection | `&`, `*` |
| Member access | `.`, `->` |
| Size | `sizeof` |
| Sequencing | comma operator |

Integer division discards the fractional part. Division or remainder by zero is invalid. The remainder operator requires integer operands.

Logical `&&` and `||` short-circuit. The right operand is evaluated only when required. This permits guarded operations such as `pointer != NULL && *pointer > 0`.

## Precedence and associativity

Precedence decides how operators group when parentheses are absent. Associativity decides grouping among operators at the same precedence level. It does not generally define the order in which operands are evaluated.

`a + b * c` groups as `a + (b * c)`. Assignment is right-associative, so `a = b = 0` groups as `a = (b = 0)`. Subtraction is left-associative, so `a - b - c` groups as `(a - b) - c`.

Avoid relying on memorized precedence in complex expressions. Parentheses communicate intent. Avoid modifying and reading the same scalar object without guaranteed sequencing.

## Implicit and explicit conversion

Integer promotions and usual arithmetic conversions bring operands to compatible types. A cast requests conversion explicitly.

```c
double average = (double) total / count;
```

The cast prevents integer division. A cast does not repair invalid data or make an unsafe pointer valid.

## Practice questions

1. Explain type, scope, storage duration, and linkage as four separate ideas.
2. Why is the exact size of `int` not fixed by the C standard?
3. Write a program that prints the size and range of major integer types.
4. Explain why signed overflow and unsigned overflow behave differently.
5. Compare automatic, static, external, and register storage-class specifiers.
6. Build and run the multi-file extern example using its README.
7. Write a safe `MAX` solution as a function and explain the limitations of a macro version.
8. Why is `SQUARE(i++)` dangerous?
9. Evaluate `2 + 3 * 4 > 10 && 5 != 0` by showing grouping and intermediate values.
10. Explain why associativity does not normally determine operand evaluation order.
11. Write a program that uses conditional compilation to enable debug output.
12. Read two integers and compute a floating average without accidental integer division.

