# C Foundations, Standards, Software and Compilation

## Why C remains important

C provides a small language core, predictable data layout, efficient compiled code, and access to memory through pointers. It is widely used when a program must interact closely with hardware or operating-system interfaces. C also influenced C++, Java, C sharp, Go, JavaScript syntax, and many other languages.

C does not automatically check array bounds, manage dynamic memory, or prevent invalid pointers. This control enables efficiency but makes correctness the programmer's responsibility.

## C language standards

Before standardization, different compilers accepted different variants. ISO and ANSI standards created a common definition.

| Standard | Common name | Important additions or role |
| --- | --- | --- |
| 1989 and 1990 | C89 or C90 | First widely adopted standardized C |
| 1995 amendment | C95 | Library and internationalization updates |
| 1999 | C99 | `//` comments, variable declarations within blocks, `long long`, variable-length arrays and designated initializers |
| 2011 | C11 | Atomics, threads, improved Unicode support, `_Static_assert`; removed `gets` |
| 2018 | C17 | Defect corrections with few new features |
| 2023 | C23 | Modernization, library additions and language cleanup |

This repository uses C17 for broad compiler support. A program is portable when it depends only on behavior guaranteed by the selected standard and handles implementation-defined properties properly.

### Behavior categories

Defined behavior has one required meaning. Implementation-defined behavior allows an implementation to choose and document a meaning, such as whether plain `char` is signed. Unspecified behavior permits one of several valid outcomes without requiring documentation. Undefined behavior has no requirements; signed integer overflow and out-of-bounds access are examples. A program containing undefined behavior cannot be reasoned about using normal expectations.

## System software and application software

System software manages hardware or provides services to other software. Examples include operating systems, device drivers, compilers, linkers, shells, and system utilities.

Application software performs tasks for a user or organization. Examples include browsers, editors, accounting systems, games, and hospital-management software.

The boundary can overlap. A database engine can be an application to an administrator and infrastructure to another application. Classification depends on purpose and context.

## Compiler and interpreter

A compiler translates source code into another form, commonly machine code or intermediate representation. The produced program can later execute without translating the complete source again.

An interpreter directly executes source or intermediate instructions through another program. Many modern runtimes combine compilation and interpretation. The distinction is about implementation strategy, not whether a language is inherently capable of one approach.

Typical compiled C advantages include fast native execution, early type diagnostics, and direct use of platform libraries. Costs include a build step, platform-specific executables, and the need to recompile after source changes.

## The C translation process

### Preprocessing

The preprocessor handles directives such as `#include`, `#define`, and conditional compilation. It produces a translation unit after header inclusion and macro expansion.

```bash
gcc -std=c17 -E examples/compilation_demo.c -o compilation_demo.i
```

### Compilation

The compiler parses and analyzes the preprocessed program, performs transformations, and commonly produces assembly.

```bash
gcc -std=c17 -S compilation_demo.i -o compilation_demo.s
```

### Assembly

The assembler converts assembly into an object file containing machine code plus metadata and unresolved references.

```bash
gcc -c compilation_demo.s -o compilation_demo.o
```

### Linking

The linker combines object files and required libraries, resolves external symbols, arranges sections, and creates an executable.

```bash
gcc compilation_demo.o -o compilation_demo
```

The one-command build performs all stages.

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic examples/compilation_demo.c -o compilation_demo
```

## Source files, headers and separate compilation

Source files normally end with `.c`. Header files normally end with `.h` and contain declarations, type definitions, constants, and carefully designed macros shared between source files. Definitions that allocate storage or provide function bodies normally belong in `.c` files.

A declaration tells the compiler that a name and type exist. A definition provides the entity or storage. A function prototype is a declaration. A function body is a definition.

Separate compilation lets a project rebuild only changed source files. The linker later combines their object files. This is the foundation of multi-file C projects.

## Hosted and freestanding implementations

A hosted implementation provides the full standard library and conventional program startup with `main`. Desktop and server programs are usually hosted. A freestanding implementation may provide only part of the library and can use a platform-specific entry point. Embedded firmware and operating-system kernels often use freestanding environments.

## Practice questions

1. Why does selecting a language standard improve portability?
2. Distinguish implementation-defined, unspecified, and undefined behavior with one example each.
3. Classify a shell, compiler, spreadsheet program, database engine, and device driver. Explain borderline cases.
4. Compare a compiler and interpreter without claiming that one is always faster.
5. Describe the output and responsibility of every C translation stage.
6. Use GCC options to produce `.i`, `.s`, `.o`, and executable files from the example. Inspect their sizes.
7. What difference exists between a declaration and definition?
8. Why should function bodies usually not be placed in ordinary header files?
9. Research is not required: using only this lesson, explain why an operating-system kernel may use a freestanding implementation.

