#include "main.h"
#include <stdarg.h>

/* _printf implementation */
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
            flags_t f = get_flags(format, &i);

            switch (format[i])
            {
                case 'c':
                    count += print_char(va_arg(args, int), buffer, &buf_index, &count);
                    break;
                case 's':
                    count += print_string(va_arg(args, char *), buffer, &buf_index, &count);
                    break;
                case 'S':
                    count += print_S(va_arg(args, char *), buffer, &buf_index, &count);
                    break;
                case 'd':
                case 'i':
                    count += print_number(va_arg(args, int), buffer, &buf_index, &count);
                    break;
                case 'u':
                    count += print_unsigned(va_arg(args, unsigned int), 10, 0, buffer, &buf_index, &count);
                    break;
                case 'o':
                    count += print_unsigned(va_arg(args, unsigned int), 8, 0, buffer, &buf_index, &count);
                    break;
                case 'x':
                    count += print_unsigned(va_arg(args, unsigned int), 16, 0, buffer, &buf_index, &count);
                    break;
                case 'X':
                    count += print_unsigned(va_arg(args, unsigned int), 16, 1, buffer, &buf_index, &count);
                    break;
                case 'p':
                    count += print_pointer(va_arg(args, void *), buffer, &buf_index, &count);
                    break;
                case '%':
                    count += print_char('%', buffer, &buf_index, &count);
                    break;
            }
        }
        else
            count += print_char(format[i], buffer, &buf_index, &count);
    }

    /* flush buffer */
    if (buf_index)
        write(1, buffer, buf_index);

    va_end(args);
    return (count);
}
