# Complete C Language Guide

This repository is a complete course for students learning C from the beginning. It follows the supplied college syllabus and adds the practical knowledge required to write, compile, debug, and test real C programs.

The repository is designed for self-study. Every chapter contains the following material.

1. Concepts explained from first principles
2. Syntax and working rules
3. Common mistakes and undefined behavior
4. Portable example programs
5. Compilation commands
6. Practice questions and programming exercises


## Syllabus coverage

| Syllabus area | Repository folder |
| --- | --- |
| C introduction, standards, software, compiler and compilation | `00_getting_started` and `01_basics` |
| Data types, storage classes, macros, preprocessor and operators | `02_data_types_storage_preprocessor` |
| Conditions, switch, loops, break, continue, exit and goto | `03_control_flow` |
| Functions, command-line arguments, call by value and reference-like behavior | `04_functions` |
| Arrays, strings, multidimensional arrays and string functions | `05_arrays_and_strings` |
| Every pointer category listed in the syllabus | `06_pointers` |
| Static and dynamic memory allocation | `07_memory_allocation` |
| Structures, unions and enumerations | `08_structures_unions_enums` |
| Text files, modes, EOF, feof and file functions | `09_file_handling` |
| Complete applications | `10_projects` |
| Revision and assessment | `11_question_bank` |
| Tables and quick revision | `12_quick_reference` |

## Recommended learning order

Study the numbered folders in order. Do not begin pointers before understanding arrays and functions. Do not begin dynamic memory before understanding pointers.

For every chapter, follow this cycle.

1. Read the complete chapter README.
2. Type each example yourself instead of only reading it.
3. Compile with warnings enabled.
4. Change inputs and predict the output before running.
5. Solve the practice questions without copying code.
6. Compare your solution with the rules explained in the chapter.

## Required tools

You need a C compiler and a terminal. GCC and Clang are both suitable. Examples are written for standard C17 unless a chapter specifically discusses another standard.

Check GCC.

```bash
gcc --version
```

Compile one program.

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic program.c -o program
./program
```

On Windows PowerShell, run the executable with this command.

```powershell
.\program.exe
```

Read `00_getting_started/README.md` for installation and compilation details.

## Verify every example

On Linux, Kali Linux, macOS, WSL, or Git Bash, run:

```bash
bash scripts/verify_examples.sh
```

This checks every C source file with strict warnings and then builds the multi-file and project examples.

## Important correctness rules

1. C always passes function arguments by value. What is commonly called call by reference in C is implemented by passing pointer values.
2. `gets` was removed from C because it cannot prevent buffer overflow. Use `fgets`.
3. `strrev`, `getch`, `putch`, and `conio.h` are not part of ISO C. Portable replacements are taught.
4. Reading an uninitialized variable, accessing an array out of bounds, dereferencing an invalid pointer, using freed memory, and modifying a string literal produce invalid or undefined behavior.
5. Compiler warnings are learning tools. Do not hide them.

## Repository learning outcomes

After completing the repository, a student should be able to:

1. Explain how C source code becomes an executable.
2. Select correct types, operators, storage duration, and scope.
3. Design conditions and loops without accidental infinite behavior.
4. Decompose programs into reusable functions.
5. safely work with arrays, strings, pointers, and dynamic memory.
6. Model records with structures, unions, and enumerations.
7. Read and write text files with correct error and EOF handling.
8. Build multi-file programs using headers and separate compilation.
9. Diagnose common compile-time, link-time, run-time, and logic errors.
10. Complete the supplied projects and question bank independently.

## Practice questions

1. Why should a beginner compile with `-Wall -Wextra -Wpedantic`?
2. What is the difference between source code, object code, and an executable?
3. Why is learning arrays before pointers helpful?
4. Which four syllabus functions are not portable or not safe, and what should replace them?
5. Compile one example with both GCC and Clang and compare the warnings.

