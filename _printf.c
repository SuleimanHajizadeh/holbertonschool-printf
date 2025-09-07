#include "main.h"
#include <stdlib.h>

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    int buf_index = 0, count = 0, i;
    flags_t f;

    if (!format)
        return (-1);

    va_start(args, format);

    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            f = get_flags(format, &i);

            if (format[i] == 'c')
                buf_index = print_char(va_arg(args, int), buffer, &buf_index, &count);
            else if (format[i] == 's')
                buf_index = print_string(va_arg(args, char *), buffer, &buf_index, &count);
            else if (format[i] == 'S')
                buf_index = print_non_printable(va_arg(args, char *), buffer, &buf_index, &count);
            else if (format[i] == '%')
                buf_index = print_char('%', buffer, &buf_index, &count);
            else if (format[i] == 'd' || format[i] == 'i')
                buf_index = print_number(va_arg(args, int), f, buffer, &buf_index, &count);
            else if (format[i] == 'b')
                buf_index = print_binary(va_arg(args, unsigned int), buffer, &buf_index, &count);
            else if (format[i] == 'u')
                buf_index = print_unsigned(va_arg(args, unsigned int), 10, 0, buffer, &buf_index, &count);
            else if (format[i] == 'o')
                buf_index = print_unsigned(va_arg(args, unsigned int), 8, 0, buffer, &buf_index, &count);
            else if (format[i] == 'x')
                buf_index = print_unsigned(va_arg(args, unsigned int), 16, 0, buffer, &buf_index, &count);
            else if (format[i] == 'X')
                buf_index = print_unsigned(va_arg(args, unsigned int), 16, 1, buffer, &buf_index, &count);
            else if (format[i] == 'p')
                buf_index = print_pointer(va_arg(args, void *), buffer, &buf_index, &count);
        }
        else
        {
            buf_index = print_char(format[i], buffer, &buf_index, &count);
        }
        i++;
    }

    if (buf_index > 0)
        write(1, buffer, buf_index);
    va_end(args);
    return (count);
}
