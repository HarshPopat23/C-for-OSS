# Control Statements

Control flow determines which statements execute and how many times they execute. Clear control flow should make program logic easy to trace.

## Truth in C

An integer, floating, or pointer scalar expression is false when it compares equal to zero and true otherwise. Relational and logical operators produce integer values `0` or `1`.

Do not confuse assignment and equality.

```c
if (value = 5) {
    /* assigns 5 and then tests true */
}

if (value == 5) {
    /* compares value with 5 */
}
```

Compiler warnings often catch accidental assignment in a condition.

## If and else

Use `if` when a block should execute only when a condition is true. An optional `else` handles the false path.

```c
if (temperature > 35) {
    printf("High temperature\n");
} else {
    printf("Temperature is not high\n");
}
```

Always using braces reduces mistakes when a block later gains another statement.

## Else-if ladder

An else-if ladder tests mutually exclusive alternatives from top to bottom. The first true branch executes and later branches are skipped. Order matters when ranges overlap.

```c
if (marks >= 90) {
    grade = 'A';
} else if (marks >= 75) {
    grade = 'B';
} else if (marks >= 60) {
    grade = 'C';
} else {
    grade = 'D';
}
```

Validate impossible input before classification.

## Switch statement

`switch` selects a branch based on an integer or enumeration expression. Case labels must be integer constant expressions and must be unique.

```c
switch (choice) {
case 1:
    printf("Add\n");
    break;
case 2:
    printf("Remove\n");
    break;
default:
    printf("Invalid choice\n");
    break;
}
```

Without `break`, execution falls through to the next case. Intentional fallthrough should be documented. A switch cannot directly express arbitrary ranges as conveniently as an else-if ladder.

## For loop

A `for` loop groups initialization, continuation test, and update.

```c
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

Execution order is initialization once, condition before each iteration, body, update, and then the next condition. Any of the three header expressions may be omitted, but the semicolons remain.

## While loop

A `while` loop checks its condition before each iteration. It is suitable when the number of iterations is not known in advance.

```c
while (scanf("%d", &value) == 1 && value >= 0) {
    total += value;
}
```

The loop body may execute zero times.

## Do-while loop

A `do-while` loop checks after the body, so the body executes at least once.

```c
do {
    printf("Enter a choice from 1 to 3: ");
    result = scanf("%d", &choice);
} while (result == 1 && (choice < 1 || choice > 3));
```

The semicolon after the closing condition is required.

## Nested loops

A loop can contain another loop. For a rectangular table, an outer loop commonly selects the row and an inner loop selects the column. If the outer loop runs `r` times and the inner loop runs `c` times per outer iteration, the body runs `r * c` times.

Consider performance when nesting loops over large inputs. Also use distinct variable names such as `row` and `column` to communicate meaning.

## Break

`break` immediately terminates the nearest enclosing loop or switch. It does not leave multiple nested loops. A flag, helper function, or redesigned condition can handle multi-level termination.

## Continue

`continue` skips the remaining body of the nearest loop and proceeds to its next iteration. In a `for` loop, the update expression still runs before the next test. Overusing `continue` can hide logic; use it when it clearly removes unnecessary nesting.

## Exit

`exit` from `<stdlib.h>` terminates the entire program. `exit(EXIT_SUCCESS)` reports success and `exit(EXIT_FAILURE)` reports failure. It flushes and closes standard I/O streams and runs functions registered with `atexit`. It does not return through active function calls.

Returning from `main` is normally clearer for ordinary completion. Use `exit` when a deeply called function must terminate the program and the design intentionally permits it.

## Goto

`goto label;` transfers control to a labeled statement within the same function.

Unstructured jumps can create tangled control flow, skip important reasoning steps, and make state difficult to track. Conditions, loops, `break`, `continue`, helper functions, and early returns usually express intent more clearly.

A limited, disciplined use appears in low-level C cleanup code where several failure paths must release resources in reverse order. A `goto` cannot jump into another function. It must not be used to bypass necessary initialization or create confusing cycles.

## Input validation and infinite loops

An infinite loop occurs when the continuation condition never becomes false. Sometimes this is intentional, as in an event loop, but it must contain a controlled termination mechanism.

When `scanf` fails on invalid text, the unread character remains in the input stream. Repeating the same `scanf` without consuming bad input causes an infinite failure loop. Line-oriented input using `fgets` followed by `strtol` is safer for serious programs.

## Practice questions

1. Write a program that classifies an integer as positive, negative, or zero.
2. Validate marks from 0 to 100 and then print a grade using an else-if ladder.
3. Create a switch-based menu for addition, subtraction, multiplication, and guarded division.
4. Print numbers from 1 to 100 using `for`, `while`, and `do-while` separately.
5. Explain when a do-while loop is more suitable than a while loop.
6. Print a multiplication table using nested loops.
7. Find the first number between 100 and 200 divisible by both 7 and 9 using `break`.
8. Print all numbers from 1 to 50 except multiples of 3 using `continue`.
9. Explain what `break` does inside a switch nested inside a loop.
10. Rewrite a goto-based menu using a loop.
11. Give one defensible cleanup use for `goto` and three bad uses.
12. Explain the difference between `return`, `break`, and `exit`.
13. Repair a loop that repeatedly calls `scanf` after invalid input.
14. Determine the time complexity of three nested loops with bounds `n`, `n`, and `10`.

