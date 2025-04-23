#ifndef _HELPERS_H_
#define _HELPERS_H_

void show_help_menu(void);
int read_request_body_per_line(int socket, char *buf, int len);
char* get_port_number();

#endif // _HELPERS_H_
