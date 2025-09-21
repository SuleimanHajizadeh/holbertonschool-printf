#include "main.h"

/**
 * print_number - prints integers
 */
int print_number(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    int n = va_arg(types, int);
    char str[50];
    int i = 0, len;

    sprintf(str, "%d", n);

    len = 0;
    while (str[len])
        len++;

    write(1, str, len);

    return (len);
}
