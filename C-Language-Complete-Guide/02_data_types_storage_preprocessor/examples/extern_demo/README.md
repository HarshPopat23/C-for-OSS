# Extern and Separate Compilation Example

`counter.h` declares the external object and function. `counter.c` defines them. `main.c` uses them.

Compile each source file, then link both object files.

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic -c counter.c
gcc -std=c17 -Wall -Wextra -Wpedantic -c main.c
gcc counter.o main.o -o extern_demo
./extern_demo
```

## Practice questions

1. What error occurs if `counter.c` is not linked?
2. Why does the header declare but not define `global_counter`?
3. Change `global_counter` to `static` in `counter.c`. Explain the link error.

