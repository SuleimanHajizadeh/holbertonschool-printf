#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    char *buff;
    int i = 0, count = 0, flags;
    va_list arg_value;
    func_ptr_t func;

    if (!format)
        return (-1);

    buff = malloc(4000);
    if (!buff)
        return (-1);

    va_start(arg_value, format);

    while (format[i])
    {
        flags = 0;
        if (format[i] != '%')
        {
            buff[count++] = format[i++];
            continue;
        }

        i++; /* skip '%' */

        /* Check for flags */
        if (format[i] == '+')
        {
            flags |= FLAG_PLUS;
            i++;
        }

        func = check_prtr(format[i]);
        if (!func)
        {
            buff[count++] = '%';
            buff[count++] = format[i++];
            continue;
        }

        count = func(&buff[count], count, arg_value, flags);
        i++;
    }

    write(1, buff, count);
    va_end(arg_value);
    free(buff);

    return count;
}
