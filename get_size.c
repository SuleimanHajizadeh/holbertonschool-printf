#include "main.h"

/**
 * get_size - calculates the size specifier
 * @format: format string
 * @i: pointer to current index
 * Return: size constant
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    if (format[curr_i] == 'l')
        size = S_LONG;
    else if (format[curr_i] == 'h')
        size = S_SHORT;
    else
        size = 0;

    if (size != 0)
        *i = curr_i;

    return (size);
}
