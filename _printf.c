#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    char *buff;
    int i = 0, count = 0;
    va_list arg_value;
    int flags;

    buff = malloc(4000);
    if (!format || !buff || (format[0] == '%' && format[1] == '\0'))
    {
        free(buff);
        exit(1);
    }

    va_start(arg_value, format);

    while (format[i])
    {
        if (format[i] != '%')
        {
            buff[count++] = format[i];
        }
        else
        {
            i++;
            flags = 0;
            if (format[i] == '+')
            {
                flags |= FLAG_PLUS;
                i++;
            }

            int (*func)(char *, int, va_list, int) = check_prtr(format[i]);
            if (!func)
            {
                buff[count++] = '%';
                buff[count++] = format[i];
            }
            else
            {
                count = func(&buff[count], 0, arg_value, flags);
            }
        }
        i++;
    }
    write(1, buff, count);
    va_end(arg_value);
    free(buff);
    return count;
}
