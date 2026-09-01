# Concise Answer Guide

This guide gives checkpoints rather than complete programming solutions. Revisit the relevant chapter when a checkpoint is unclear.

## Foundations

1. A C implementation includes the translator and execution environment needed to support a defined form of C.
2. Source contains C text; preprocessing creates a translation unit; compilation and assembly create object code; linking creates the executable from objects and libraries.
3. The four common stages are preprocessing, compilation, assembly, and linking.
4. Separate compilation builds translation units independently and relinks their object files.
5. Compiler translates language, assembler translates assembly, linker resolves and combines objects, loader prepares execution, and interpreter executes through another program.
6. System software supports hardware or other programs; application software performs end-user or organizational tasks.
7. Standards define a portable contract across implementations.
8. The behavior categories differ in how many meanings are allowed and whether documentation or any requirements exist.
9. It requests C17 conformance mode from the compiler.
10. Warnings often identify legal but suspicious code and likely defects.

## High-value checkpoints

11. The standard specifies minimum ranges and relationships so C can support varied architectures.
12. Signed overflow is undefined; unsigned arithmetic wraps modulo its range.
15. Scope is visibility, storage duration is lifetime, and linkage connects declarations.
17. Static-storage objects receive zero initialization before explicit initialization.
20. Macros are token substitution, enumerators are named integer constants, and const-qualified objects have type and storage.
22. A macro can evaluate an argument more than once.
23. Precedence and associativity control grouping; evaluation order controls when operands execute.
24. `&&` and `||` evaluate the right side only when needed.
31. Break leaves the nearest loop or switch, return leaves a function, and exit terminates the program.
39. Parameters receive copied values; modification of an ordinary parameter does not alter the caller.
40. A copied pointer value can still designate the caller's object, which the function changes by dereferencing.
41. Array parameters adjust to pointers and carry no length metadata.
43. `strtol` reports where conversion stopped and can report range failure.
45. An automatic local's lifetime ends when its function returns.
49. The sizeof expression works only where the identifier has array type, not after parameter adjustment to pointer.
50. A C string is a character sequence terminated by `\0`.
52. `gets` receives no capacity and cannot know when the destination is full.
55. `strcmp` guarantees only negative, zero, or positive sign categories.
57. All read a character; getchar uses stdin, while getc and fgetc accept a stream and getc may be a macro.
58. `int` must represent every unsigned-char value plus the distinct negative `EOF`.
59. These interfaces belong to compiler-specific console libraries rather than ISO C.
63. Pointer arithmetic is valid within the same array and one-past; one-past cannot be dereferenced.
66. `int *a[5]` is an array of pointers; `int (*a)[5]` is a pointer to an array.
68. Valid choices include caller-owned live storage, static storage, appropriately const string literals, and allocated storage with documented ownership.
70. Const placement controls whether the pointee, pointer object, or both may change.
72. If realloc fails, the original allocation remains valid; direct assignment would lose its address.
73. Ownership carries release responsibility; borrowing grants access without transfer of release responsibility.
76. A structure gives each member storage; union members share storage.
78. Padding, type widths, byte order, and representations vary.
84. EOF is set only after an input attempt fails at the end, so the input operation must control the loop.

## Debugging checkpoints

101. The final iteration uses index five, but the last valid index is four. Use `i < 5`.
102. A string literal must not be modified. Use `char text[] = "hello"` for an editable copy or `const char *text` for read-only access.
103. The local object ceases to exist after return. Use caller-provided storage, intentionally static storage, or allocated storage with ownership documentation.
104. Store realloc's result in a temporary pointer and update the owner only on success.
105. Place `fgets` in the loop condition and inspect `ferror` after the loop.
106. The unparenthesized expansion is `2 + 3 * 2 + 3`. Parenthesize the replacement and every parameter, but avoid side-effecting arguments.
107. The expression assigns two, evaluates true, and always enters the block. Equality uses `==`.
108. Some `char` representations cannot distinguish all byte values from `EOF`. Store the result in `int`.

## Practice questions

1. Expand each checkpoint into a three-sentence explanation.
2. Write complete answers to the questions omitted from this concise guide.
3. Review every answer by locating the supporting chapter section.

