# Syllabus Coverage Checklist

This checklist maps every item visible in the supplied syllabus to its lesson and code.

## Basics

| Required item | Main explanation | Code |
| --- | --- | --- |
| C language introduction | `00_getting_started` and `01_basics` | `hello.c`, `compilation_demo.c` |
| C language standards | `01_basics` | Standard compilation commands |
| System software | `01_basics` | Conceptual classification exercises |
| Application software | `01_basics` | Conceptual classification exercises |
| Compiler | `01_basics` | GCC commands |
| Compilation process | `01_basics` | Preprocessed, assembly, object, and executable commands |
| Compiler and interpreter | `01_basics` | Comparison and practice questions |

## Data, preprocessing and control

| Required item | Main explanation | Code |
| --- | --- | --- |
| Different data types | `02_data_types_storage_preprocessor` | `types_and_limits.c` |
| auto | Same chapter | `storage_duration.c` |
| static | Same chapter | `storage_duration.c` |
| extern | Same chapter | `extern_demo` multi-file program |
| register | Same chapter | `storage_duration.c` |
| Macro and preprocessor | Same chapter | `macros_and_conditionals.c` |
| Operator precedence and associativity | Same chapter | `operators.c` |
| If-else | `03_control_flow` | `grade_classifier.c` |
| If-else-if ladder | Same chapter | `grade_classifier.c` |
| Switch case | Same chapter | `switch_calculator.c` |
| for, while and do-while | Same chapter | `loops.c` |
| Nested loop | Same chapter | `nested_break_continue.c` |
| break and continue | Same chapter | `nested_break_continue.c` |
| exit | Same chapter | Explanation and exercises |
| goto and its problems | Same chapter | `structured_cleanup.c` and structured alternatives |

## Functions, arrays and strings

| Required item | Main explanation | Code |
| --- | --- | --- |
| Functions | `04_functions` | `functions_basics.c` |
| Arguments in main | Same chapter | `command_line_sum.c` |
| Call by value | Same chapter | `value_and_pointer.c` |
| Call by reference terminology | Same chapter | Pointer-based modification in `value_and_pointer.c` |
| Array introduction | `05_arrays_and_strings` | `numeric_arrays.c` |
| Number array | Same chapter | `numeric_arrays.c` |
| Character array and string | Same chapter | `string_library.c` |
| Multidimensional array | Same chapter | `matrix.c` |
| User-defined string operations | Same chapter | `string_toolkit.c` |
| strlen, strcpy, strcmp | Same chapter | Standard and custom examples |
| strrev | Same chapter | Portable custom implementation and non-standard warning |
| gets | Same chapter | Removal explanation and safe `fgets` replacement |
| puts | Same chapter | `string_library.c` |
| getc and fgetc | Same chapter and `09_file_handling` | File character examples |
| getch | `05_arrays_and_strings` | Non-standard explanation and portable alternative |
| getchar | Same chapter | `character_io.c` |
| putc and fputc | Same chapter and `09_file_handling` | `file_copy.c` |
| putch | `05_arrays_and_strings` | Non-standard explanation and portable alternative |
| putchar | Same chapter | Multiple examples |

## Pointers and allocation

| Required item | Main explanation | Code |
| --- | --- | --- |
| Pointer introduction | `06_pointers` | `pointer_basics.c` |
| Double pointer | Same chapter | `pointer_basics.c` |
| Pointer to int | Same chapter | `pointer_basics.c` |
| Pointer to char | Same chapter | `character_and_pointer_array.c` |
| Pointer to function | Same chapter | `function_pointers.c` |
| Function returning pointer | Same chapter | `function_returning_pointer.c` |
| Pointer to array | Same chapter | `pointer_to_array.c` |
| Pointer to structure | Same chapter | `pointer_to_structure.c` |
| Array of pointers | Same chapter | `character_and_pointer_array.c` |
| Static allocation | `07_memory_allocation` | Storage-duration comparison |
| Dynamic allocation | Same chapter | All examples |
| malloc | Same chapter | `malloc_calloc.c`, `dynamic_input.c` |
| calloc | Same chapter | `malloc_calloc.c` |
| realloc | Same chapter | `resizable_array.c` |
| free | Same chapter | All allocation examples |

## Records and files

| Required item | Main explanation | Code |
| --- | --- | --- |
| Structure | `08_structures_unions_enums` | `structures.c` |
| Union | Same chapter | `tagged_union.c` |
| Enum | Same chapter | `enum_menu.c` and `tagged_union.c` |
| Text-file basics | `09_file_handling` | All file examples |
| Read, write and append | Same chapter | `read_lines.c`, `write_append.c` |
| EOF and feof | Same chapter | Correct read-loop examples |
| File pointer | Same chapter | All file examples |
| fopen | Same chapter | All file examples |
| fgetc | Same chapter | `file_copy.c`, `file_statistics.c` |
| fgets | Same chapter | `read_lines.c` |
| fputc | Same chapter | `file_copy.c` |
| fprintf | Same chapter | `write_append.c` |

## Practice questions

1. Mark each row only after you can explain and code the item without notes.
2. Select five related rows and build one program combining them.
3. Identify three places where the repository teaches safer or more precise information than the syllabus wording.

