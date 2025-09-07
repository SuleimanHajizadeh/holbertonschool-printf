#include "main.h"

flags_t get_flags(const char *format, int *i)
{
    flags_t f = {0, 0, 0};
    int j = *i;

    while (format[j] == '+' || format[j] == ' ' || format[j] == '#')
    {
        if (format[j] == '+')
            f.plus = 1;
        if (format[j] == ' ')
            f.space = 1;
        if (format[j] == '#')
            f.hash = 1;
        j++;
    }

    *i = j - 1;
    return f;
}
