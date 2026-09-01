#include <stdio.h>

static int file_private_value = 100;

static int next_id(void)
{
    static int id = 0;
    id++;
    return id;
}

int main(void)
{
    auto int automatic_value = 5;
    register int suggested_fast_value = 7;
    int first_id = next_id();
    int second_id = next_id();
    int third_id = next_id();

    printf("automatic: %d\n", automatic_value);
    printf("register: %d\n", suggested_fast_value);
    printf("file private: %d\n", file_private_value);
    printf("ids: %d %d %d\n", first_id, second_id, third_id);
    return 0;
}
