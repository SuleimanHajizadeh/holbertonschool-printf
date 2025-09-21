#include "main.h"

/**
 * print_string - prints a string
 */
int print_string(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    char *str = va_arg(types, char *);
    int len = 0;

    if (!str)
        str = "(null)";

    while (str[len])
        len++;

    write(1, str, len);
    return (len);
}
