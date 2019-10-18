#include <stdio.h>
#include <string.h>

void show_help_menu(void);

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("Missing arguments, please specify port number.\n");
        show_help_menu();
        return 128;
    } else if (argc > 2) {
        printf("Too many arugments were provided, please refer the manuals below.\n");
        show_help_menu();
        return 1;
    }


    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        show_help_menu();
        return 0;
    }

    printf("Serving HTTP on 0.0.0.0 port %s (http://0.0.0.0:%s/) ...\n", argv[1], argv[1]);
    printf("Quit the server with CONTROL-C.\n");

    return 0;
}

void show_help_menu(void)
{
    printf("WIP: help menu here ...\n");
}
