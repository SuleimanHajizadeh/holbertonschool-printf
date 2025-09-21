#include "main.h"

/**
 * _printf - Custom printf implementation
 */
int _printf(const char *format, ...)
{
    int i, count = 0, printed = 0;
    int flags, width, precision, size, buf_index = 0;
    va_list args;
    char buffer[1024];

    if (!format)
        return (-1);

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buf_index++] = format[i];
            if (buf_index == 1024)
            {
                write(1, buffer, buf_index);
                buf_index = 0;
            }
            count++;
        }
        else
        {
            int j = i + 1;

            flags = get_flags(format, &j);
            width = get_width(format, &j, args);
            precision = get_precision(format, &j, args);
            size = get_size(format, &j);

            ++j;
            printed = handle_print(format, &j, args, buffer,
                                   flags, width, precision, size);
            if (printed == -1)
                return (-1);
            count += printed;
            i = j;
        }
    }

    if (buf_index > 0)
        write(1, buffer, buf_index);

    va_end(args);

    return (count);
}
