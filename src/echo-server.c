#include <stdio.h>  // printf(), stderror()
#include <string.h>
#include <errno.h> // errno
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h> // read()
#include <stdlib.h> // atoi(), exit()
#include <ctype.h>  // isdigit()

#include "helpers.h" // show_help_menu(), read_request_body_per_line()


int main(int argc, char *argv[]) {
    char port[5];

    // validation: argument parse
    if (argc > 2) {
        printf("Too many arugments were provided, please refer the manuals below.\n\n");
        show_help_menu();
        exit(1);
    }

    else if (argc == 2) {
      // when provided LISTEN_PORT and argment at the same time, the LISTEN_PORT has been used
      if (getenv("LISTEN_PORT") == NULL) {
          strcpy(port, argv[1]);
      } else {
          strcpy(port, getenv("LISTEN_PORT"));
      }

      if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
          printf("echo-server is a simple HTTP server with C implementation\n\n");
          show_help_menu();
          exit(0);
      }

      // Check types of arguments
      int l = strlen(argv[1]);
      int result = 1;
      for (int i = 0; i < l && result == 1; i++) {
          result = isdigit(argv[1][i]);
      }
      if (result == 0) {
          printf("%s is not a number, please specify the port number to open.\n", argv[1]);
          exit(1);
      }

      // Check max port number
      if (!(0 < atoi(argv[1]) ) || !(atoi(argv[1]) < 65536)) {
          printf("Port number [ %s ] is invalid, should be lower than 65535.\n", argv[1]);
          exit(1);
      }

    }

    else if (argc == 1) {
      if (getenv("LISTEN_PORT") == NULL) {
          printf("Please specify port number to listen, either using LISTEN_PORT or providing as CLI arguments.\n");
          show_help_menu();
          exit(1);
        } else {
          strcpy(port, getenv("LISTEN_PORT"));
      }
    }


    // start app
    printf("Serving HTTP on 0.0.0.0 port %s (http://0.0.0.0:%s/) ...\n", port, port);
    printf("Quit the server with CONTROL-C.\n");

    // Create sockets
    int rsock = socket(AF_INET, SOCK_STREAM, 0);
    // Assign address to socket
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;

    // Cast from char atoi int for listen port
    addr.sin_port = htons(atoi(port));

    addr.sin_addr.s_addr = INADDR_ANY;
    // bind socket
    int ret = bind(rsock, (struct sockaddr *)&addr, sizeof(addr));
    if (ret != 0) {
        printf("Failed to bind socket.\n");
        exit(1);
    }

    printf("Starting application now.\n");
    // array for storing request body
    char resp[255];
    while (1) {
        // listen
        listen(rsock, 5);
        // awaiting connection
        int wsock;
        int len;
        struct sockaddr_in client;

        len = sizeof(client);
        wsock = accept(rsock, (struct sockaddr *)&client, &len);
        if (wsock == -1) {
            fprintf(stderr, "Failed to accept with socket: code %s\n", strerror(errno));
            exit(1);
        }

        printf("Got response\n");
        read_request_body_per_line(wsock, resp, sizeof(resp));

        // char *resp = "HTTP1.1 200 OK\n";
        write(wsock, resp, strlen(resp));

        // disconnect and clear values in array
        close(wsock);
        memset(resp, 0, sizeof(resp));
    }

    exit(0);
}
