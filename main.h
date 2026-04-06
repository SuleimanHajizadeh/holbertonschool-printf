#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * struct print - Struct op
 *
 * @t: The operator
 * @f: The function associated
 */
typedef struct print
{
	char t;
	int (*f)(va_list);
} print_t;

int _printf(const char *format, ...);
int get_printf(const char c, va_list ap);

int pchar(va_list arg);
int pstr(va_list arg);
int pperc(va_list arg);
int pint(va_list arg);
int pbin(va_list arg);
int puns(va_list arg);
int poct(va_list arg);
int phex(va_list arg);
int pHEX(va_list arg);
int pSTR(va_list arg);
int ppntr(va_list arg);
int prevs(va_list arg);
int proot(va_list arg);

int intlen(int a);
int hexa(unsigned int n);

#endif