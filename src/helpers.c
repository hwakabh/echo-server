#include <stdio.h>      // printf()
#include <unistd.h>     // read()
#include <stdlib.h>     // exit(), getenv()
#include <string.h>     // strcpy()


void show_help_menu(void) {
  printf("Usage: echo-server <port>\n");
  exit(0);
}

int read_request_body_per_line(int socket, char *buf, int len) {
  // array to store strings (a single line in reqbody)
  char *s = buf;
  int l = len;

  // read character in a single line
  int c = read(socket, s, l);
  // apply to array until last char become line-break
  while ((c > 0) && (s[c-1] != '\n')) {
      s += c;
      l = -c;
      c = read(socket, s ,l);
  }
  if (c < 0) {
    return c;
  }

  return len - l;
}

char* get_port_number(char* t) {
  char* p;
  if (getenv("LISTEN_PORT") == NULL) {
      strcpy(p, t);
  } else {
      strcpy(p, getenv("LISTEN_PORT"));
  }

}
