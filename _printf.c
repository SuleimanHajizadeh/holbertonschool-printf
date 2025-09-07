#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom printf implementation
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    int buf_index = 0, count = 0, i;

    if (!format)
        return (-1);

    va_start(args, format);

    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
                buf_index = print_char(va_arg(args, int), buffer, &buf_index, &count);
            else if (format[i] == 's')
                buf_index = print_string(va_arg(args, char *), buffer, &buf_index, &count);
            else if (format[i] == '%')
                buf_index = print_char('%', buffer, &buf_index, &count);
            else if (format[i] == 'd' || format[i] == 'i')
                buf_index = print_number(va_arg(args, int), buffer, &buf_index, &count);
            else if (format[i] == 'b')
                buf_index = print_binary(va_arg(args, unsigned int), buffer, &buf_index, &count);
            else if (format[i] == 'u')
                buf_index = print_unsigned(va_arg(args, unsigned int), 10, 0,
                                           buffer, &buf_index, &count);
            else if (format[i] == 'o')
                buf_index = print_unsigned(va_arg(args, unsigned int), 8, 0,
                                           buffer, &buf_index, &count);
            else if (format[i] == 'x')
                buf_index = print_unsigned(va_arg(args, unsigned int), 16, 0,
                                           buffer, &buf_index, &count);
            else if (format[i] == 'X')
                buf_index = print_unsigned(va_arg(args, unsigned int), 16, 1,
                                           buffer, &buf_index, &count);
            else if (format[i] == 'S')
                buf_index = print_S(va_arg(args, char *), buffer, &buf_index, &count);
            else
                buf_index = print_char(format[i], buffer, &buf_index, &count);
        }
        else
        {
            buf_index = print_char(format[i], buffer, &buf_index, &count);
        }
    }

    if (buf_index > 0)
        write(1, buffer, buf_index);

    va_end(args);
    return (count);
}
