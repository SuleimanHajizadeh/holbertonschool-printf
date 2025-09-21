#include "main.h"

int get_flags(const char *format, int *i)
{
    int flags = 0;
    int j = *i;

    while (format[j])
    {
        if (format[j] == '+')
            flags |= FLAG_PLUS;
        else if (format[j] == ' ')
            flags |= FLAG_SPACE;
        else if (format[j] == '#')
            flags |= FLAG_HASH;
        else
            break;
        j++;
    }

    *i = j - 1;
    return flags;
}
