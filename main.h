#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/* _printf function */
int _printf(const char *format, ...);

/* Printing functions */
int print_char(char c, char *buffer, int *buf_index, int *count);
int print_string(char *s, char *buffer, int *buf_index, int *count);
int print_number(int n, char *buffer, int *buf_index, int *count);
int print_unsigned(unsigned int n, int base, int uppercase,
                   char *buffer, int *buf_index, int *count);
int print_binary(unsigned int n, char *buffer, int *buf_index, int *count);
int print_pointer(void *ptr, char *buffer, int *buf_index, int *count);

/* Flags structure */
typedef struct flags
{
    int plus;
    int space;
    int hash;
} flags_t;

flags_t get_flags(const char *format, int *i);

#endif /* MAIN_H */
