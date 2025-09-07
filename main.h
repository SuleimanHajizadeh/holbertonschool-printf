#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/* _printf */
int _printf(const char *format, ...);

/* Helper functions */
int print_char(char c, char *buffer, int *buf_index);
int print_string(char *s, char *buffer, int *buf_index);
int print_number(long n, char *buffer, int *buf_index);
int print_unsigned_long(unsigned long n, int base, int uppercase,
                        char *buffer, int *buf_index);
int print_pointer(void *p, char *buffer, int *buf_index);

/* Length modifiers */
typedef enum length
{
    NONE,
    SHORT,
    LONG
} length_t;

#endif
