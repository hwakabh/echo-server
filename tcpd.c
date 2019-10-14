#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Serving HTTP on 0.0.0.0 port %s (http://0.0.0.0:%s/) ...\n", argv[1], argv[1]);
    printf("Quit the server with CONTROL-C.\n");
    return 0;
}
