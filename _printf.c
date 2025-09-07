#include "main.h"
#include <stdarg.h>
#include <unistd.h>

#define BUF_SIZE 1024

flags_t get_flags(const char *format, int *i)
{
    flags_t f;
    f.plus = 0;
    f.space = 0;
    f.hash = 0;

    while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#')
    {
        if (format[*i] == '+')
            f.plus = 1;
        else if (format[*i] == ' ')
            f.space = 1;
        else if (format[*i] == '#')
            f.hash = 1;
        (*i)++;
    }
    return f;
}

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[BUF_SIZE];
    int buf_index = 0, count = 0;
    int i;
    flags_t f;

    va_start(args, format);

    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            f = get_flags(format, &i);

            if (format[i] == 'c')
                buf_index = print_char(va_arg(args, int), buffer, &buf_index, &count);
            else if (format[i] == 's')
                buf_index = print_string(va_arg(args, char *), buffer, &buf_index, &count);
            else if (format[i] == 'd' || format[i] == 'i')
                buf_index = print_number(va_arg(args, int), f, buffer, &buf_index, &count);
            else if (format[i] == 'u')
                buf_index = print_unsigned(va_arg(args, unsigned int), 10, 0, f, buffer, &buf_index, &count);
            else if (format[i] == 'o')
                buf_index = print_unsigned(va_arg(args, unsigned int), 8, 0, f, buffer, &buf_index, &count);
            else if (format[i] == 'x')
                buf_index = print_unsigned(va_arg(args, unsigned int), 16, 0, f, buffer, &buf_index, &count);
            else if (format[i] == 'X')
                buf_index = print_unsigned(va_arg(args, unsigned int), 16, 1, f, buffer, &buf_index, &count);
            else if (format[i] == '%')
                buf_index = print_char('%', buffer, &buf_index, &count);
        }
        else
        {
            buf_index = print_char(format[i], buffer, &buf_index, &count);
        }

        if (buf_index >= BUF_SIZE - 1)
        {
            write(1, buffer, buf_index);
            buf_index = 0;
        }
        i++;
    }

    if (buf_index > 0)
        write(1, buffer, buf_index);

    va_end(args);
    return count;
}
