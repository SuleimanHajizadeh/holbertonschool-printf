#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int func_x(char *buff, int count, va_list value, int flags)
{
    unsigned int num = va_arg(value, unsigned int);
    char *str = _lcutoa(num, 16);

    if ((flags & FLAG_HASH) && num != 0)
    {
        buff[count++] = '0';
        buff[count++] = 'x';
    }

    return _assign(&buff[count], 0, str);
}
