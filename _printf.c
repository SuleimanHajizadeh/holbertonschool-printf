u#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    int buf_index, count, i;
    length_t length; /* from previous tasks, optional for l/h */
    flags_t f;
    char ch;

    buf_index = 0;
    count = 0;
    i = 0;

    if (!format)
        return -1;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            f = get_flags(format, &i);

            switch (format[i])
            {
                case 'c':
                    ch = va_arg(args, int);
                    count += print_char(ch, buffer, &buf_index);
                    break;
                case 's':
                    count += print_string(va_arg(args, char *), buffer, &buf_index);
                    break;
                case '%':
                    count += print_char('%', buffer, &buf_index);
                    break;
                /* Add numeric specifiers here as needed */
            }
        }
        else
            count += print_char(format[i], buffer, &buf_index);

        i++;
    }

    if (buf_index)
        write(1, buffer, buf_index);

    va_end(args);
    return count;
}
