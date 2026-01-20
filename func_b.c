#include "main.h"
#include <stdarg.h>

int func_b(char *buff, int count, va_list value, int flags)
{
    unsigned int num = va_arg(value, unsigned int);
    char *str = _utoa(num, 2);

    (void)flags;
    return _assign(&buff[count], 0, str);
}
