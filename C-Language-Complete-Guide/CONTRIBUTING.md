# Contributing

This educational repository welcomes corrections, clearer explanations, additional portable examples, test cases, and practice problems.

## Contribution rules

1. Use ISO C17 unless the lesson is explicitly about another standard.
2. Compile with `-Wall -Wextra -Wpedantic` and resolve every reasonable warning.
3. Avoid compiler-specific libraries unless the lesson clearly labels them non-standard.
4. Never teach `gets` as usable code.
5. Every new concept explanation must end with practice questions.
6. Every new example must explain its input, output, and important edge cases.
7. Do not use emojis or decorative symbols.
8. Keep language direct and suitable for first-year students.

## Pull request checklist

1. Run `bash scripts/verify_examples.sh`.
2. Confirm the example does not invoke undefined behavior.
3. Add at least three practice questions for a new lesson.
4. Check spelling, formatting, and relative links.
5. Explain why the change improves student learning.

## Practice questions

1. Why must educational examples compile with strict warnings?
2. What information should a bug report contain?
3. How can a reviewer check whether code relies on a non-standard feature?

