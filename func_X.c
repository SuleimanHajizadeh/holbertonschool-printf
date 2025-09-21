#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int func_X(char *buff, int count, va_list value, int flags)
{
    unsigned int num = va_arg(value, unsigned int);
    char *str = _utoa(num, 16);

    if ((flags & FLAG_HASH) && num != 0)
    {
        buff[count++] = '0';
        buff[count++] = 'X';
    }

    return _assign(&buff[count], 0, str);
}
