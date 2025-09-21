#include "main.h"
#include <stdarg.h>

/**
 * get_precision - retrieves precision for printing
 * @format: format string
 * @i: pointer to current index
 * @args: arguments list
 * Return: precision value
 */
int get_precision(const char *format, int *i, va_list args)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] == '.')
    {
        curr_i++;
        precision = 0;

        if (format[curr_i] == '*')
        {
            precision = va_arg(args, int);
            curr_i++;
        }
        else
        {
            while (is_digit(format[curr_i]))
                precision = precision * 10 + (format[curr_i++] - '0');
        }
    }

    *i = curr_i - 1;
    return (precision);
}
