#include "main.h"

/**
 * print_percent - prints a percent
 */
int print_percent(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    (void)types;
    (void)buffer;
    (void)flags;
    (void)width;
    (void)precision;
    (void)size;

    write(1, "%", 1);
    return (1);
}
