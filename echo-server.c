#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

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

    // Create sockets
    int rsock = socket(AF_INET, SOCK_STREAM, 0);
    // Assign address to socket
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8088);
    addr.sin_addr.s_addr = INADDR_ANY;
    // bind socket
    int ret = bind(rsock, (struct sockaddr *)&addr, sizeof(addr));
    // listen
    listen(rsock, 5);
    // awaiting connection
    int wsock;
    int len;
    struct sockaddr_in client;

    len = sizeof(client);
    wsock = accept(rsock, (struct sockaddr *)&client, &len);
    write(wsock, "HTTP1.1 200 OK\n", 15);

    return 0;
}

void show_help_menu(void)
{
    printf("WIP: help menu here ...\n");
}
