#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* _printf function */
int _printf(const char *format, ...);

/* Helper functions */
int print_char(char c, char *buffer, int *buf_index);
int print_string(char *s, char *buffer, int *buf_index);
int print_number(long n, char *buffer, int *buf_index);
int print_unsigned_long(unsigned long n, int base, int uppercase,
                        char *buffer, int *buf_index);
int print_pointer(void *p, char *buffer, int *buf_index);

/* Flag struct for +, space, # */
typedef struct flags
{
    int plus;
    int space;
    int hash;
} flags_t;

flags_t get_flags(const char *format, int *i);

#endif
