#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* FLAGS */
#define F_MINUS  1
#define F_PLUS   2
#define F_ZERO   4
#define F_HASH   8
#define F_SPACE  16

/* SIZES */
#define S_LONG   2
#define S_SHORT  1

/**
 * struct fmt - Struct op
 *
 * @fmt: format
 * @fn: The function associated
 */
typedef struct fmt
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

/* Prototypes */
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list,
    char buffer[], int flags, int width, int precision, int size);

/* utils */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

/* write handlers */
int handle_write_char(char c, char buffer[],
    int flags, int width, int precision, int size);

/* print functions */
int print_char(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_number(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* flag, width, precision, size handlers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

#endif /* MAIN_H */
