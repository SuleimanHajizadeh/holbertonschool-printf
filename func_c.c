#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int func_c(char *buff, int count, va_list value, int flags)
{
    int ch = va_arg(value, int);
    (void)flags;

    buff[count] = ch;
    return count + 1;
}
