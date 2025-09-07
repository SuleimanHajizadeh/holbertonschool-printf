#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, count = 0;

    va_start(args, format);

    if (!format)
        return (-1);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                count += print_char(va_arg(args, int));
            else if (format[i] == 's')
                count += print_string(va_arg(args, char *));
            else if (format[i] == '%')
                count += print_char('%');
            else if (format[i] == 'd' || format[i] == 'i')
                count += print_number(va_arg(args, int));
            else if (format[i] == 'b')
                count += print_binary(va_arg(args, unsigned int));
            else if (format[i] == 'u')
                count += print_unsigned(va_arg(args, unsigned int), 10, 0);
            else if (format[i] == 'o')
                count += print_unsigned(va_arg(args, unsigned int), 8, 0);
            else if (format[i] == 'x')
                count += print_unsigned(va_arg(args, unsigned int), 16, 0);
            else if (format[i] == 'X')
                count += print_unsigned(va_arg(args, unsigned int), 16, 1);
            else
            {
                count += print_char('%');
                count += print_char(format[i]);
            }
        }
        else
        {
            count += print_char(format[i]);
        }
    }

    va_end(args);
    return (count);
}
