# Project 2: Student Record Manager

This menu-driven project stores records in a text file. It demonstrates structures, arrays, safe line input, parsing, file write and append modes, searching, and validation.

Compile and run:

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic student_records.c -o student_records
./student_records
```

Records are stored as `roll|name|marks`. Names containing the separator character are rejected. This is a teaching format, not a full escaping standard.

## Practice questions

1. Add record update and deletion using a validated temporary file.
2. Prevent duplicate roll numbers before append.
3. Sort listed records by roll number, name, and marks.
4. Replace the fixed line buffer with a dynamically growing line reader.
5. Design escaping rules that permit the separator inside names.
6. Split the program into model, storage, input, and main modules.

