#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int i, count = 0, buf_index = 0;
    char buffer[1024];

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++; /* move to specifier */
            if (format[i] == 'p')
                buf_index = print_pointer(va_arg(args, void *), buffer, &buf_index, &count);
            else
                buf_index = print_char(format[i], buffer, &buf_index, &count);
        }
        else
        {
            buf_index = print_char(format[i], buffer, &buf_index, &count);
        }
    }

    va_end(args);
    return (count);
}
