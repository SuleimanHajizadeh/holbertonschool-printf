#include "main.h"

flags_t get_flags(const char *format, int *i)
{
    flags_t f;
    f.plus = 0;
    f.space = 0;
    f.hash = 0;

    while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#')
    {
        if (format[*i] == '+')
            f.plus = 1;
        else if (format[*i] == ' ')
            f.space = 1;
        else if (format[*i] == '#')
            f.hash = 1;
        (*i)++;
    }
    return f;
}
