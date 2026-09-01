#!/usr/bin/env bash
set -euo pipefail

repository_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
build_directory="$repository_root/build"

mkdir -p "$build_directory"

example_number=0
while IFS= read -r source; do
    gcc -std=c17 -Wall -Wextra -Wpedantic -Werror -fsyntax-only "$source"
    if grep -Eq '^[[:space:]]*int[[:space:]]+main[[:space:]]*\(' "$source" &&
       [[ "$source" != *"/extern_demo/main.c" ]]; then
        gcc -std=c17 -Wall -Wextra -Wpedantic -Werror \
            "$source" -o "$build_directory/example_$example_number"
        example_number=$((example_number + 1))
    fi
done < <(find "$repository_root" -name '*.c' -type f | sort)

gcc -std=c17 -Wall -Wextra -Wpedantic -Werror \
    "$repository_root/02_data_types_storage_preprocessor/examples/extern_demo/main.c" \
    "$repository_root/02_data_types_storage_preprocessor/examples/extern_demo/counter.c" \
    -o "$build_directory/extern_demo"

for project in calculator student_records text_analyzer matrix_toolkit; do
    gcc -std=c17 -Wall -Wextra -Wpedantic -Werror \
        "$repository_root/10_projects/$project/$project.c" \
        -o "$build_directory/$project"
done

"$build_directory/calculator" add 12 7 >/dev/null
"$build_directory/calculator" multiply -4 6 >/dev/null
if "$build_directory/calculator" divide 10 0 >/dev/null 2>&1; then
    echo "Calculator failed to reject division by zero" >&2
    exit 1
fi
"$build_directory/matrix_toolkit" >/dev/null
"$build_directory/text_analyzer" "$repository_root/README.md" >/dev/null
"$build_directory/extern_demo" >/dev/null

echo "All C files passed strict syntax checks and project smoke tests."
