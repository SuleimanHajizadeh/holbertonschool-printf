#include "main.h"
#include <stdarg.h>

/**
 * print_binary - prints an unsigned int in binary using buffer
 * @args: va_list containing the number
 * @buffer: buffer array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: number of characters printed
 */
int print_binary(va_list args, char buffer[], int flags, int width,
                 int precision, int size)
{
    unsigned int n = va_arg(args, unsigned int);
    int i = 0;
    char bin[32];

    if (n == 0)
    {
        bin[i++] = '0';
    }
    else
    {
        while (n > 0)
        {
            bin[i++] = (n % 2) + '0';
            n /= 2;
        }
    }

    /* Reverse into buffer */
    for (int j = 0; j < i; j++)
        buffer[j] = bin[i - j - 1];

    return (handle_write_char(buffer, i, flags, width, precision, size));
}
