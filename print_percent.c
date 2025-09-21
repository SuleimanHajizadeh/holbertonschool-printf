#include "main.h"

/**
 * print_percent - Prints a percent sign
 * @types: Unused
 * @buffer: Buffer array
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
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
    return (write(1, "%%", 1));
}
