# Static and Dynamic Memory Allocation

Memory management is about object lifetime, size, ownership, and valid access. The phrase static allocation is often used broadly in introductory courses, but C defines several storage durations.

## Storage-duration overview

### Static storage duration

File-scope objects and objects declared with `static` exist for the entire program. Their size is determined before execution and they are zero-initialized before explicit initialization.

### Automatic storage duration

Ordinary local objects exist while their block is active. Their sizes are usually fixed when the block is entered. They are managed automatically and must not be accessed after their lifetime ends.

### Allocated storage duration

Dynamic memory is requested during execution from the allocator. It remains allocated until explicitly released with `free` or until the program terminates. The programmer controls its lifetime.

Dynamic allocation is useful when size is known only at run time, data must outlive a function call, or a flexible structure such as a linked list is required.

## malloc

`malloc(size)` requests at least `size` bytes and returns a suitably aligned pointer to uninitialized storage, or `NULL` on failure.

```c
int *values = malloc(count * sizeof(*values));
```

Using `sizeof(*values)` keeps the allocation correct if the pointed type changes. In C, do not cast the return value of `malloc`; a cast can hide a missing `<stdlib.h>` declaration in old code.

The multiplication must not overflow. Check `count > SIZE_MAX / sizeof(*values)` before multiplying when count may be untrusted or very large.

## calloc

`calloc(count, element_size)` allocates space for an array and initializes all bits to zero.

```c
int *counts = calloc(count, sizeof(*counts));
```

All-bits-zero represents integer zero, but do not generalize this guarantee to every possible type representation outside what C specifies. `calloc` also makes the count and element size explicit and can detect multiplication overflow in conforming implementations.

## realloc

`realloc(pointer, new_size)` changes the size of an existing allocation and may move it. Existing bytes are preserved up to the smaller of old and new sizes. Additional bytes are uninitialized.

Use a temporary pointer.

```c
int *temporary = realloc(values, new_count * sizeof(*values));
if (temporary == NULL) {
    /* values is still valid */
} else {
    values = temporary;
}
```

Assigning directly to `values` would lose the original allocation if reallocation failed, causing a memory leak.

Special behavior involving a requested size of zero has portability complications across standards. Use `free(pointer)` when the intention is to release memory.

## free

`free(pointer)` releases storage previously returned by an allocation function. `free(NULL)` is safe and does nothing.

After `free`, every pointer into that allocation becomes dangling and must not be dereferenced. Setting one owning variable to `NULL` does not repair other aliases.

Each allocation must be freed exactly once. Freeing a pointer not returned by an allocator, freeing the same allocation twice, or freeing an interior element address is undefined behavior.

## Ownership

Ownership answers who is responsible for calling `free`. A function interface should make ownership clear.

Common patterns:

1. Caller allocates and passes a buffer; caller frees it.
2. Function allocates and returns ownership; caller frees it.
3. Structure owns its fields; a matching destroy function frees fields and structure.
4. Borrowed pointer grants temporary access but not ownership.

Avoid returning dynamically allocated memory without documenting who releases it.

## Common dynamic-memory failures

### Memory leak

Allocated storage becomes unreachable without being freed. Repeated leaks can exhaust memory.

### Use after free

Code accesses an allocation after release. The memory may already be reused.

### Double free

The same allocation is freed more than once.

### Buffer overflow

Code writes outside allocated bounds. This can corrupt data and create security vulnerabilities.

### Uninitialized read

Memory from `malloc` and newly extended `realloc` regions contain indeterminate data. Initialize before reading.

### Incorrect allocation size

Using `malloc(count)` for an integer array allocates bytes rather than integers. Use `count * sizeof(*pointer)` with overflow validation.

## Resizable array strategy

A dynamic array tracks a pointer, logical length, and capacity. When length reaches capacity, allocate a larger block, commonly double the capacity. Geometric growth keeps average append cost constant while limiting reallocations.

Before doubling, check for arithmetic overflow. Update the owning pointer only after successful reallocation.

## Memory debugging

Compiler sanitizers can detect many invalid accesses during testing.

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -fsanitize=address,undefined -g program.c -o program
./program
```

Valgrind is another tool on supported platforms. Tools improve detection but do not replace ownership design and code review.

## Practice questions

1. Distinguish static, automatic, and allocated storage duration.
2. Allocate an integer array of a user-supplied size with overflow and failure checks.
3. Compare `malloc` and `calloc`.
4. Explain why `malloc` should not be cast in C.
5. Expand an array with `realloc` using a temporary pointer.
6. Explain what remains valid when `realloc` fails.
7. Define leak, dangling pointer, use after free, double free, and buffer overflow.
8. Design ownership rules for a dynamically allocated student record containing a dynamically allocated name.
9. Implement a resizable integer vector with append, print, and destroy functions.
10. Explain why setting one pointer to `NULL` after `free` does not fix aliases.
11. Use AddressSanitizer to diagnose an intentionally out-of-bounds practice program, then remove the defect.
12. Prove why geometric capacity growth is more efficient than growing by one element for every append.

