# Getting Started

## What C is

C is a general-purpose, procedural programming language created for implementing systems software. It gives programmers direct control over memory and data representation while still providing structured functions, expressions, conditions, and loops. Operating systems, compilers, embedded firmware, database engines, networking software, and performance-sensitive libraries commonly contain C.

C is described as a compiled language because an implementation normally translates the entire source program into machine code before execution. The C standard defines the language and standard library behavior. A compiler implementation supplies the translator, library, linker integration, and platform-specific details.

## Installing a compiler

### Debian, Ubuntu and Kali Linux

```bash
sudo apt update
sudo apt install build-essential
gcc --version
```

### Fedora

```bash
sudo dnf install gcc make
gcc --version
```

### Windows

Use one of these approaches.

1. Install MSYS2 and its MinGW GCC toolchain.
2. Install Visual Studio Build Tools and use the Microsoft C compiler.
3. Use Windows Subsystem for Linux and follow the Ubuntu instructions.

The course commands use GCC. With Microsoft C, command options differ but C concepts remain the same.

## The smallest useful program

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, C\n");
    return 0;
}
```

`#include <stdio.h>` makes declarations for standard input and output functions available. `main` is the program entry point in a hosted C implementation. `void` states that this form of `main` receives no parameters. `printf` writes formatted output. `return 0` reports successful termination to the environment.

## Compile and run

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic examples/hello.c -o hello
./hello
```

Important options:

| Option | Meaning |
| --- | --- |
| `-std=c17` | Request the C17 language standard |
| `-Wall` | Enable a useful set of warnings |
| `-Wextra` | Enable additional warnings |
| `-Wpedantic` | Warn about extensions outside the selected standard |
| `-o hello` | Name the produced executable `hello` |

Warnings are not always errors, but a beginner should investigate each warning. A successful build does not prove that program logic is correct.

## Four kinds of errors

### Compile-time error

The source violates grammar or type rules that the compiler detects. A missing semicolon is a common example.

### Link-time error

Compilation produces object code, but the linker cannot find a required definition. Calling a declared function without linking its implementation is an example.

### Run-time error

The program starts but fails during execution. Examples include invalid memory access and division by zero.

### Logic error

The program runs but computes the wrong result. Logic errors require tests and reasoning because the compiler may not detect them.

## Basic terminal workflow

```bash
mkdir c_practice
cd c_practice
touch program.c
gcc -std=c17 -Wall -Wextra -Wpedantic program.c -o program
./program
```

On Windows, create a file using the editor rather than `touch` if that command is unavailable.

## Reading compiler diagnostics

A diagnostic normally includes a filename, line number, column number, severity, and message. Read the first error first because one early mistake can cause many later messages. Do not randomly change code. Identify the rule that the diagnostic refers to.

## Practice questions

1. What responsibilities belong to the C standard and what responsibilities belong to a compiler implementation?
2. Explain every line of the hello program without using the words obvious or simply.
3. Compile the example after removing the semicolon. Record the first diagnostic.
4. Change `main` to return `1`. Run the program and inspect the shell exit status with `echo $?`.
5. Give one example of each of the four error categories.
6. Why does a warning-free build not prove correctness?

