#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/* Functions match prototype from main.h */
int func_c(char *buff, int count, va_list value, int flags)
{
    (void)flags;
    buff[count] = va_arg(value, int);
    return (1);
}

int func_s(char *buff, int count, va_list value, int flags)
{
    char *str;
    int i;

    (void)flags;
    str = va_arg(value, char *);
    i = 0;
    while (str[i])
    {
        buff[count + i] = str[i];
        i++;
    }
    return (i);
}

int func_ptg(char *buff, int count, va_list value, int flags)
{
    (void)value;
    (void)flags;
    buff[count] = '%';
    return (1);
}
