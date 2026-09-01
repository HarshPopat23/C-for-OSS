#include <stdio.h>

enum MenuChoice {
    MENU_ADD = 1,
    MENU_LIST = 2,
    MENU_EXIT = 3
};

int main(void)
{
    int input;

    printf("1 Add\n2 List\n3 Exit\nChoice: ");
    if (scanf("%d", &input) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    switch ((enum MenuChoice) input) {
    case MENU_ADD:
        puts("Add selected");
        break;
    case MENU_LIST:
        puts("List selected");
        break;
    case MENU_EXIT:
        puts("Exit selected");
        break;
    default:
        puts("Unknown choice");
        break;
    }
    return 0;
}

