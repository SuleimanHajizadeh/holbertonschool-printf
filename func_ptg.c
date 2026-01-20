#include "main.h"
#include <stdarg.h>

int func_ptg(char *buff, int count, va_list value, int flags)
{
    (void)value;
    (void)flags;

    buff[count] = '%';
    return count + 1;
}
