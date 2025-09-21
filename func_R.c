#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int func_R(char *buff, int count, va_list value, int flags)
{
    char *str = va_arg(value, char *);
    char *encoded_str;
    (void)flags;

    if (!str)
        str = "(null)";

    encoded_str = malloc(_strlen(str) + 1);
    _strcpy(encoded_str, str);
    _rot13(encoded_str);

    count = _assign(&buff[count], 0, encoded_str);
    free(encoded_str);

    return count;
}
