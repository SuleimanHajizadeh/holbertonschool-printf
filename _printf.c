#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    int buf_index, count, i;
    char ch;

    buf_index = 0;
    count = 0;
    i = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            /* flags_t f = get_flags(format, &i); unused for now */

            switch (format[i])
            {
                case 'c':
                    ch = va_arg(args, int);
                    count += print_char(ch, buffer, &buf_index);
                    break;
                case 's':
                    count += print_string(va_arg(args, char *), buffer, &buf_index);
                    break;
                case 'd':
                case 'i':
                    count += print_number(va_arg(args, int), buffer, &buf_index);
                    break;
                case 'u':
                    count += print_unsigned(va_arg(args, unsigned int), 10, 0, buffer, &buf_index);
                    break;
                case 'x':
                    count += print_unsigned(va_arg(args, unsigned int), 16, 0, buffer, &buf_index);
                    break;
                case 'X':
                    count += print_unsigned(va_arg(args, unsigned int), 16, 1, buffer, &buf_index);
                    break;
                case 'p':
                    count += print_pointer(va_arg(args, void *), buffer, &buf_index);
                    break;
                case '%':
                    count += print_char('%', buffer, &buf_index);
                    break;
            }
        }
        else
        {
            count += print_char(format[i], buffer, &buf_index);
        }
        i++;
    }

    if (buf_index)
        write(1, buffer, buf_index);

    va_end(args);
    return (count);
}
