/* func_d.c */
#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * func_d - Adds a signed integer to the buffer considering flags
 * @buff: buffer to store the output
 * @count: current index in the buffer
 * @value: va_list containing the integer
 * @flags: formatting flags (e.g., FLAG_PLUS)
 * Return: updated count after adding the number
 */
int func_d(char *buff, int count, va_list value, int flags)
{
    int num = va_arg(value, int);
    char *str;

    /* Handle '+' flag for positive numbers */
    if ((flags & FLAG_PLUS) && num >= 0)
        buff[count++] = '+';

    str = _itoa(num, 10);
    count = _assign(&buff[count], 0, str);

    return count;
}

/**
 * func_i - Just calls func_d (integer specifier behaves the same)
 * @buff: buffer to store the output
 * @count: current index in the buffer
 * @value: va_list containing the integer
 * @flags: formatting flags (e.g., FLAG_PLUS)
 * Return: updated count after adding the number
 */
int func_i(char *buff, int count, va_list value, int flags)
{
    return func_d(buff, count, value, flags);
}
