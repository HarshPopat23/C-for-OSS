# File Handling

File handling lets data persist after a program ends. This chapter focuses on text files and standard C streams.

## Streams and file pointers

C represents an open stream with a `FILE` object declared in `<stdio.h>`. Programs use a `FILE *` to interact with it. Standard streams are `stdin`, `stdout`, and `stderr`.

```c
FILE *file = fopen("notes.txt", "r");
```

Always check the returned pointer. `NULL` means opening failed. Use `perror` or `strerror(errno)` to report the operating-system error when appropriate.

## File modes

| Mode | Meaning | Existing content | If file is absent |
| --- | --- | --- | --- |
| `r` | Read | Preserved | Open fails |
| `w` | Write | Truncated | Created |
| `a` | Append | Preserved; writes go to end | Created |
| `r+` | Read and write | Preserved | Open fails |
| `w+` | Read and write | Truncated | Created |
| `a+` | Read and append | Preserved; writes go to end | Created |

Add `b` for binary mode, such as `rb` or `wb`. On systems where text and binary modes differ, text mode may translate line endings or treat certain values specially.

## Closing files

`fclose(file)` flushes pending output and releases stream resources. It returns zero on success and `EOF` on failure. Output errors can be detected only during flushing or closing, so important programs check the return value.

After `fclose`, the pointer no longer refers to an open stream and must not be reused.

## Character input with fgetc and getc

`fgetc(file)` reads the next byte as an unsigned char converted to `int`, or returns `EOF`. Store the result in `int`.

Correct loop:

```c
int character;
while ((character = fgetc(file)) != EOF) {
    putchar(character);
}
```

`getc(file)` has similar behavior but may be a macro. Do not pass an expression with side effects as its stream argument.

## Character output with fputc and putc

`fputc(character, file)` and `putc(character, file)` write one character. They return the written value converted to unsigned char or `EOF` on failure.

Check output errors when data integrity matters.

## Line input with fgets

```c
char buffer[256];
while (fgets(buffer, sizeof(buffer), file) != NULL) {
    fputs(buffer, stdout);
}
```

`fgets` reads at most one less than the specified capacity, includes a newline when it fits, and null-terminates the buffer on success. A long logical line may require multiple calls. The program must decide whether chunks are acceptable or whether to assemble them dynamically.

## Formatted output with fprintf

`fprintf` works like `printf` but receives a destination stream.

```c
fprintf(file, "%d,%s,%.2f\n", roll, name, marks);
```

It returns the number of characters written or a negative value on failure. For structured data, define escaping rules. A simple comma-separated line fails if a text field contains a comma, quote, or newline unless those characters are handled.

`fscanf` can read formatted input, but it is often fragile for real text files. Line-oriented `fgets` plus parsing functions gives better error reporting and recovery.

## EOF and feof

`EOF` is a negative integer constant returned by character input functions to indicate that no character was produced. It can mean end-of-file or an input error.

`feof(file)` becomes true only after an input operation attempts to read past the end. Therefore this is wrong:

```c
while (!feof(file)) {
    /* reads can fail and old data can be processed again */
}
```

Instead, make the input function control the loop and inspect the reason afterward.

```c
while (fgets(buffer, sizeof(buffer), file) != NULL) {
    /* process successful input */
}

if (ferror(file)) {
    /* input error */
} else if (feof(file)) {
    /* normal end-of-file */
}
```

`clearerr(file)` clears end-of-file and error indicators when recovery is intentional.

## File position

`fseek`, `ftell`, and `rewind` control or inspect stream position. Portable random access is easier in binary streams. Text-stream positions have restrictions, so use values returned by `ftell` with `fseek` rather than assuming byte offsets.

## Read, write and append workflows

### Write

Open with `w`, validate the pointer, write, check results, and close. Existing content is destroyed as soon as opening succeeds.

### Append

Open with `a`. Every write is positioned at the end according to append semantics. This is suitable for logs and adding records.

### Read

Open with `r`, loop based on successful input, then distinguish EOF from error and close.

### Update

Update modes permit both input and output. When switching between reading and writing on an update stream, follow the standard's positioning or flushing requirements. Simpler programs often close and reopen in the required mode.

## Error-handling pattern

1. Check `fopen`.
2. Check every important read or write.
3. Let the I/O result control loops.
4. Use `ferror` to distinguish an error from normal EOF.
5. Check `fclose` for output streams.
6. Preserve the original file if a replacement operation fails.

For safely replacing important content, write a temporary file, close and validate it, then rename it over the original using platform-appropriate guarantees.

## Practice questions

1. Explain every file mode and what happens to existing content.
2. Copy one text file to another using `fgetc` and `fputc`.
3. Copy a file line by line using `fgets` and `fputs`.
4. Count bytes, lines, words, digits, and letters in a text file.
5. Append a timestamp-free study log entry to a file.
6. Write student records with `fprintf` and read them with `fgets` plus parsing.
7. Explain why `while (!feof(file))` is incorrect.
8. Distinguish EOF and an input error after a failed read.
9. Explain why the result of `fgetc` must be stored in `int`.
10. Check and report failures from `fopen`, `fprintf`, and `fclose`.
11. Explain text mode versus binary mode.
12. Design a safe update process that avoids destroying the original file after a partial failure.
13. Explain why writing raw structures is not a portable file format.

