#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Flags structure */
typedef struct flags
{
    int plus;
    int space;
    int hash;
} flags_t;

/* _printf prototype */
int _printf(const char *format, ...);

/* Printing helpers */
int print_char(char c, char *buffer, int *buf_index);
int print_string(char *s, char *buffer, int *buf_index);
int print_number(int n, char *buffer, int *buf_index, flags_t f);

/* Flags handler */
flags_t get_flags(const char *format, int *i);

#endif
