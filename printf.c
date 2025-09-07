#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - simplified printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, count = 0;

    va_start(args, format);

    for (i = 0; format && format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                count += print_char(va_arg(args, int));
            else if (format[i] == 's')
                count += print_string(va_arg(args, char *));
            else if (format[i] == 'd' || format[i] == 'i')
                count += print_number(va_arg(args, int));
            else if (format[i] == 'b')
                count += print_binary(va_arg(args, unsigned int));
            else
                count += print_char(format[i]);
        }
        else
            count += print_char(format[i]);
    }

    va_end(args);
    return (count);
}
