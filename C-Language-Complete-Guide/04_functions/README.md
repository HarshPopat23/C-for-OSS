# Functions and Program Arguments

Functions divide a program into named units with clear responsibilities. A good function performs one coherent task, exposes a small interface, validates assumptions when appropriate, and avoids hidden global-state dependencies.

## Declaration, definition and call

A function declaration tells the compiler the function name, return type, and parameter types.

```c
int maximum(int left, int right);
```

A definition provides the body.

```c
int maximum(int left, int right)
{
    return left > right ? left : right;
}
```

A call evaluates arguments and transfers control to the function.

```c
int larger = maximum(12, 8);
```

Place public declarations in headers. Define functions once in source files. A prototype enables the compiler to check argument and return types.

## Parameters and arguments

Parameters are local variables declared in the function definition. Arguments are expressions supplied by a call. Arguments are converted to their corresponding parameter types when permitted.

In `int add(int a, int b)`, `a` and `b` are parameters. In `add(x, 5)`, `x` and `5` are arguments.

## Return values

A non-void function returns a value compatible with its declared return type on every reachable completion path. A `void` function returns no value and may use `return;` for early completion.

Never return the address of an automatic local variable. That object ceases to exist after the function returns. Returning a pointer to static storage, dynamically allocated storage, or caller-provided storage can be valid when ownership is documented.

## Function scope and local state

Parameters and block variables are local to the function or nested block. Local automatic variables from separate calls are independent. A block-scope static variable retains state across calls, which can be useful but makes testing and concurrency harder.

## C uses call by value

C always passes arguments by value. The function receives a copy of each argument value. Modifying a normal parameter does not modify the caller's object.

```c
void ineffective_swap(int a, int b)
{
    int temporary = a;
    a = b;
    b = temporary;
}
```

This swaps only the local copies.

## Reference-like behavior with pointers

To modify a caller's object, pass its address. The pointer itself is still passed by value, but dereferencing it accesses the caller's object.

```c
void swap(int *a, int *b)
{
    int temporary = *a;
    *a = *b;
    *b = temporary;
}
```

Call it using `swap(&x, &y)`. The function must require non-null, valid pointers. For a public interface, validate pointers or clearly document the precondition.

This mechanism is commonly called call by reference in introductory syllabi, but the precise description is pass-by-value of pointer values.

## Arrays as parameters

In a function parameter declaration, `int values[]` is adjusted to `int *values`. The function does not receive an entire copied array and cannot determine its length from `sizeof(values)`. Pass the length separately.

```c
double average(const int values[], size_t length);
```

`const` states that the function will not modify elements through this parameter.

## Passing arguments to main

The portable parameterized form is:

```c
int main(int argc, char *argv[])
```

`argc` is the argument count and is at least one in a hosted implementation. `argv` is an array of pointers to strings. `argv[0]` normally identifies the program. `argv[1]` through `argv[argc - 1]` are command-line arguments. `argv[argc]` is a null pointer.

All arguments are text. Convert numeric input using robust functions such as `strtol`, which can report invalid text and range errors. `atoi` cannot distinguish invalid input from a valid zero and should not be used for validated input.

Example:

```bash
./command_line_sum 10 20 -5
```

Shell quoting determines how spaces are grouped into a single argument.

## Recursion

A recursive function calls itself directly or indirectly. It requires a base case that terminates recursion and a recursive step that moves toward that base case. Each call normally uses a new stack frame.

Recursion can express tree traversal and divide-and-conquer algorithms naturally. Deep recursion can exhaust stack space. An iterative solution is often preferable for simple counting tasks.

## Function design rules

1. Give a function one clear responsibility.
2. Use meaningful names based on actions or computed results.
3. Keep parameter lists small and coherent.
4. Prefer returning a value for a single result.
5. Use pointer output parameters when multiple results are required.
6. Use `const` for data that should not be modified.
7. Document ownership for returned or accepted pointers.
8. Avoid global variables when parameters and return values are sufficient.
9. Separate input/output from calculation where practical.

## Practice questions

1. Distinguish a function declaration, definition, call, parameter, and argument.
2. Write and test functions for minimum, maximum, absolute value, and integer power.
3. Demonstrate why an ordinary swap function cannot modify caller variables.
4. Write a pointer-based swap that safely handles null pointers.
5. Explain precisely why C is not call by reference.
6. Write a function that returns both quotient and remainder through output parameters.
7. Write an array average function that accepts a length and does not modify the array.
8. Explain why `sizeof` on an array parameter does not return the original array size.
9. Write a command-line program that accepts integers and reports their minimum, maximum, and sum using `strtol`.
10. Compare recursion and iteration for factorial. State overflow and input limitations.
11. Why is returning the address of a local automatic variable invalid?
12. Design a header for a reusable integer-statistics module.

