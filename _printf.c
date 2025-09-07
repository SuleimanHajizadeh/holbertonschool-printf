#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    int buf_index = 0, count = 0, i;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%' && format[i + 1] == 'p')
        {
            i++;
            buf_index = print_pointer(va_arg(args, void *), buffer, &buf_index, &count);
        }
        else
            buf_index = print_char(format[i], buffer, &buf_index, &count);
    }

    if (buf_index > 0)
        write(1, buffer, buf_index);

    va_end(args);
    return count;
}
