#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int func_u(char *buff, int count, va_list value, int flags)
{
    unsigned int num = va_arg(value, unsigned int);
    char *str = _utoa(num, 10);

    (void)flags;  /* Unsigned üçün flag-lar əhəmiyyətsizdir */
    return _assign(&buff[count], 0, str);
}
