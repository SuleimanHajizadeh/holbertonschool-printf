#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 1024

/* FLAG MACROS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZE MACROS */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
typedef struct fmt
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

/* Prototypes */
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
    va_list list, char buffer[], int flags, int width, int precision, int size);

/* Utils */
int is_digit(char c);
int _strlen(char *s);
int _isdigit(int c);

/* Flag/Size/Width/Precision handlers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Print functions */
int print_char(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Add your integer, unsigned, hex, octal, etc. prototypes */

#endif
