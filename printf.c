#include "main.h"

int _printf(const char *format, ...)
{
    char *buff;
    int i = 0, count = 0;
    va_list arg_value;
    func_ptr_t func;

    buff = malloc(4000);
    if (!buff || !format)
        return -1;

    va_start(arg_value, format);

    while (format[i])
    {
        if (format[i] != '%')
            buff[count++] = format[i];
        else
        {
            int flags = 0;

            /* Check + flag */
            if (format[i + 1] == '+')
            {
                flags |= FLAG_PLUS;
                i++;
            }

            func = check_prtr(format[i + 1]);
            if (!func)
            {
                buff[count++] = '%';
                if (flags & FLAG_PLUS)
                    buff[count++] = '+';
                i++;
                continue;
            }
            count = func(&buff[count], count, arg_value, flags);
            i++;
        }
        i++;
    }

    write(1, buff, count);
    va_end(arg_value);
    free(buff);
    return count;
}
