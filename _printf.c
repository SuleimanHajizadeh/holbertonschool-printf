#include "main.h"
#include <stdarg.h>

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
        if (format[i] == '%')
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
            else if (format[i] == 'u' || format[i] == 'o' || format[i] == 'x' || format[i] == 'X')
                buf_index = print_unsigned(va_arg(args, unsigned int),
                                          (format[i] == 'o') ? 8 : (format[i] == 'x' || format[i] == 'X') ? 16 : 10,
                                          (format[i] == 'X') ? 1 : 0,
                                          buffer, &buf_index, &count);
            else if (format[i] == 'p')
                buf_index = print_pointer(va_arg(args, void *), buffer, &buf_index, &count);
        }
        else
            buf_index = print_char(format[i], buffer, &buf_index, &count);
    }

    if (buf_index > 0)
        write(1, buffer, buf_index);

    va_end(args);
    return (count);
}
