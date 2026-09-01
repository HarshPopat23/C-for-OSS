# Project 3: Text File Analyzer

The analyzer accepts a file path and counts bytes, lines, words, uppercase letters, lowercase letters, digits, whitespace, and other characters.

Compile and run:

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic text_analyzer.c -o text_analyzer
./text_analyzer README.md
```

The program casts input to `unsigned char` before calling `<ctype.h>` functions, as required for defined behavior with non-ASCII byte values.

## Practice questions

1. Add the longest line length.
2. Count occurrences of every byte value using an array of 256 counters.
3. Print the ten most common case-insensitive words.
4. Process multiple input files supplied on the command line.
5. Explain what this byte-oriented program cannot correctly infer about Unicode text.

