#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

typedef struct flags
{
    unsigned int plus : 1;
    unsigned int space : 1;
    unsigned int hash : 1;
} flags_t;

int _printf(const char *format, ...);
int print_char(char c, char *buffer, int *buf_index, int *count);
int print_string(char *s, char *buffer, int *buf_index, int *count);
int print_number(int n, flags_t f, char *buffer, int *buf_index, int *count);
int print_unsigned(unsigned int n, int base, int uppercase, flags_t f,
                   char *buffer, int *buf_index, int *count);
int print_binary(unsigned int n, char *buffer, int *buf_index, int *count);

#endif
