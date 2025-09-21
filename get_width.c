#include "main.h"
#include <stdarg.h>

/**
 * get_width - retrieves the width for printing
 * @format: format string
 * @i: pointer to current index
 * @args: arguments list
 * Return: width
 */
int get_width(const char *format, int *i, va_list args)
{
    int curr_i = *i + 1;
    int width = 0;

    if (format[curr_i] == '*')
    {
        width = va_arg(args, int);
        curr_i++;
    }
    else
    {
        while (is_digit(format[curr_i]))
            width = width * 10 + (format[curr_i++] - '0');
    }

    *i = curr_i - 1;
    return (width);
}
