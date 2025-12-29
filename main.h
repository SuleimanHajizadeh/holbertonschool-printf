#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* FLAGS */
#define FLAG_PLUS  1
#define FLAG_SPACE 2
#define FLAG_HASH  4

/* FUNCTION POINTER TYPE */
typedef int (*func_ptr_t)(char *, int, va_list, int);

/* STRUCTS */
typedef struct ptr
{
    char *c;
    func_ptr_t f;
} ptr_ch;

/* _printf & Checker */
int _printf(const char *format, ...);
func_ptr_t check_prtr(char specifier);
int _putchar(char c);

/* FUNC_* HANDLERS */
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

/* HELPERS */
int _assign(char *buff, int count, char *value);
int _rev_assign(char *buff, int count, char *value);
int _strlen(char *s);
char *_reverse(char *s, int n);
char *_rot13(char *str);
void _strcpy(char *dest, char *src);
void _rev_ptr(char *str);
int _abs(int n);
char *_itoa(int value, int base);
char *_utoa(unsigned int value, unsigned int base);
char *_lcutoa(unsigned int value, unsigned int base);

#endif
