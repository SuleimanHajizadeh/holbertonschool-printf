#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Flags */
#define FLAG_PLUS 1

/* Function pointer struct */
typedef struct ptr
{
    char *c;
    int (*f)(char *, int, va_list, int);
} ptr_ch;

/* _printf and checker */
int _printf(const char *format, ...);
int (*check_prtr(char specifier))(char *, int, va_list, int);

/* Assign functions */
int _assign(char *buff, int count, char *value);
int _rev_assign(char *buff, int count, char *value);

/* String functions */
int _strlen(char *s);
char *_reverse(char *s, int n);
char *_rot13(char *str);
void _strcpy(char *dest, char *src);
void _rev_ptr(char *str);

/* Int/Uint functions */
int _abs(int n);
char *_itoa(int value, int base);
char *_utoa(unsigned int value, unsigned int base);
char *_lcutoa(unsigned int value, unsigned int base);

/* Parameter functions */
int func_d(char *buff, int count, va_list value, int flags);
int func_i(char *buff, int count, va_list value, int flags);
int func_u(char *buff, int count, va_list value, int flags);
int func_o(char *buff, int count, va_list value, int flags);
int func_x(char *buff, int count, va_list value, int flags);
int func_X(char *buff, int count, va_list value, int flags);
int func_c(char *buff, int count, va_list value, int flags);
int func_s(char *buff, int count, va_list value, int flags);
int func_ptg(char *buff, int count, va_list value, int flags);
int func_b(char *buff, int count, va_list value, int flags);
int func_r(char *buff, int count, va_list value, int flags);
int func_R(char *buff, int count, va_list value, int flags);

#endif
