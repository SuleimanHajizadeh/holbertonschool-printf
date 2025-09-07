#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    int buf_index, count, i;
    char ch;
    length_t length;

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
            length = NONE;

            /* Check length modifiers */
            if (format[i] == 'l')
            {
                length = LONG;
                i++;
            }
            else if (format[i] == 'h')
            {
                length = SHORT;
                i++;
            }

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
                    if (length == LONG)
                        count += print_number(va_arg(args, long), buffer, &buf_index);
                    else if (length == SHORT)
                        count += print_number((short)va_arg(args, int), buffer, &buf_index);
                    else
                        count += print_number(va_arg(args, int), buffer, &buf_index);
                    break;
                case 'u':
                case 'o':
                case 'x':
                case 'X':
                    if (length == LONG)
                        count += print_unsigned_long(va_arg(args, unsigned long),
                                                    (format[i] == 'o' ? 8 : (format[i] == 'x' || format[i] == 'X') ? 16 : 10),
                                                    (format[i] == 'X'), buffer, &buf_index);
                    else if (length == SHORT)
                        count += print_unsigned_long((unsigned short)va_arg(args, unsigned int),
                                                    (format[i] == 'o' ? 8 : (format[i] == 'x' || format[i] == 'X') ? 16 : 10),
                                                    (format[i] == 'X'), buffer, &buf_index);
                    else
                        count += print_unsigned_long(va_arg(args, unsigned int),
                                                    (format[i] == 'o' ? 8 : (format[i] == 'x' || format[i] == 'X') ? 16 : 10),
                                                    (format[i] == 'X'), buffer, &buf_index);
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
