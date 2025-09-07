#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

/* _printf main function */
int _printf(const char *format, ...);

/* Helper print functions */
int print_char(char c, char *buffer, int *buf_index, int *count);
int print_string(char *s, char *buffer, int *buf_index, int *count);
int print_number(int n, char *buffer, int *buf_index, int *count);
int print_unsigned(unsigned int n, int base, int uppercase,
                   char *buffer, int *buf_index, int *count);
int print_pointer(void *p, char *buffer, int *buf_index, int *count);
int print_S(char *s, char *buffer, int *buf_index, int *count);

/* Flags struct */
typedef struct flags {
    int plus;
    int space;
    int hash;
} flags_t;

/* Flag parser */
flags_t get_flags(const char *format, int *i);

#endif
