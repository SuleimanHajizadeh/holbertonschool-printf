#include "main.h"
#include <stdarg.h>

int func_s(char *buff, int count, va_list value, int flags)
{
    char *str = va_arg(value, char *);
    (void)flags;

    if (!str)
        str = "(null)";

    return _assign(&buff[count], 0, str);
}
