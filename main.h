#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* _printf function */
int _printf(const char *format, ...);

/* Format handler */
int handle_format(const char format, va_list args);

/* Output functions */
int _putchar(char c);
int print_string(char *s);

#endif /* MAIN_H */

