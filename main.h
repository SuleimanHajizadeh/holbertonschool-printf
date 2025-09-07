#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/* Structure to hold flags */
typedef struct flags
{
    int plus;
    int space;
    int hash;
} flags_t;

/* _printf function */
int _printf(const char *format, ...);

/* Helper functions */
int print_char(char c, char *buffer, int *buf_index, int *count);
int print_string(char *s, char *buffer, int *buf_index, int *count);
int print_number(int n, flags_t f, char *buffer, int *buf_index, int *count);
int print_unsigned(unsigned int n, int base, int uppercase,
                   char *buffer, int *buf_index, int *count);
int print_binary(unsigned int n, char *buffer, int *buf_index, int *count);
int print_pointer(void *p, char *buffer, int *buf_index, int *count);
int print_non_printable(char *s, char *buffer, int *buf_index, int *count);

/* Flags parser */
flags_t get_flags(const char *format, int *i);

#endif
