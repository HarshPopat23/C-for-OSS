# Project 1: Command-Line Calculator

The calculator accepts an operation and two integer operands. It uses a function pointer table so selection and calculation remain separate.

Compile and run:

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic calculator.c -o calculator
./calculator add 12 7
./calculator divide 20 4
```

The program uses `strtol` for validated conversion, checks division by zero, and rejects arithmetic that would overflow an `int`.

## Practice questions

1. Add remainder and power operations.
2. Explain and test every overflow check in the reference implementation.
3. Support floating-point operands using `strtod`.
4. Replace the linear operation search with a menu-driven switch.
5. Write at least eight command-line test cases.
