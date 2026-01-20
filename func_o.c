#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int func_o(char *buff, int count, va_list value, int flags)
{
    unsigned int num = va_arg(value, unsigned int);
    char *str = _utoa(num, 8);

    if ((flags & FLAG_HASH) && num != 0)
        buff[count++] = '0';

    return _assign(&buff[count], 0, str);
}
