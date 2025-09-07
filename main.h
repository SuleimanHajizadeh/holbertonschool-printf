#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(char c);
int print_string(char *s);
int print_number(int n);
int print_binary(unsigned int n);
int print_unsigned(unsigned int n, int base, int uppercase,
                   char *buffer, int *buf_index, int *count);

#endif /* MAIN_H */
