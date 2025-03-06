#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h> // getenv(), atoi()
#include <ctype.h>  // isdigit()

// prototypes
void show_help_menu(void);
int is_string_digit(char *argv[]);


int main(int argc, char *argv[])
{
    // validation: argument parse
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

    // Check types of arguments
    int l = strlen(argv[1]);
    int result = 1;
    for (int i = 0; i < l && result ; i++) {
        result = isdigit(argv[1][i]);
    }
    if (result != 1) {
        printf("%s is not a number, please specify the port number to open.\n", argv[1]);
        return 1;
    }

    // Check max port number
    if (!(0 < atoi(argv[1]) ) || !(atoi(argv[1]) < 65536)) {
        printf("Port number [ %s ] is invalid, should be lower than 65535.\n", argv[1]);
        return 1;
    }

    // TODO: enable to override with envar `LISTEN_PORT`
    // Fetch port number to expose
    // char *envar_hostname = getenv("HOME");
    // printf("%s \n", envar_hostname);

    printf("Serving HTTP on 0.0.0.0 port %s (http://0.0.0.0:%s/) ...\n", argv[1], argv[1]);
    printf("Quit the server with CONTROL-C.\n");

    // Create sockets
    int rsock = socket(AF_INET, SOCK_STREAM, 0);
    // Assign address to socket
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;

    // Cast from char atoi int for listen port
    addr.sin_port = htons(atoi(argv[1]));

    addr.sin_addr.s_addr = INADDR_ANY;
    // bind socket
    int ret = bind(rsock, (struct sockaddr *)&addr, sizeof(addr));
    if (ret != 0) {
        printf("Failed to bind socket.\n");
        return 1;
    }

    while (1) {
        // listen
        listen(rsock, 5);
        // awaiting connection
        int wsock;
        int len;
        struct sockaddr_in client;

        len = sizeof(client);
        wsock = accept(rsock, (struct sockaddr *)&client, &len);

        char *resp = "HTTP1.1 200 OK\n";
        write(wsock, resp, strlen(resp));
        printf("Got response\n");

        close(wsock);
    }

    return 0;
}

void show_help_menu(void)
{
    printf("WIP: help menu here ...\n");
}
