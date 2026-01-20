#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int func_r(char *buff, int count, va_list value, int flags)
{
    char *str = va_arg(value, char *);
    char *rev_str;
    (void)flags;

    if (!str)
        str = "(null)";

    rev_str = malloc(_strlen(str) + 1);
    _strcpy(rev_str, str);
    _rev_ptr(rev_str);

    count = _assign(&buff[count], 0, rev_str);
    free(rev_str);

    return count;
}
