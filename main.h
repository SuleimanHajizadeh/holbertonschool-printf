#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

int print_char(char c, char *buffer, int *buf_index, int *count);
int print_string(char *s, char *buffer, int *buf_index, int *count);
int print_number(int n, char *buffer, int *buf_index, int *count);
int print_binary(unsigned int n, char *buffer, int *buf_index, int *count);
int print_unsigned(unsigned int n, int base, int uppercase,
                   char *buffer, int *buf_index, int *count);

#endif
