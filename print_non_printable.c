#include "main.h"
#include <stdarg.h>

/**
 * print_non_printable - prints non-printable chars as hex using buffer
 * @args: va_list containing the string
 * @buffer: buffer array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: number of characters printed
 */
int print_non_printable(va_list args, char buffer[], int flags, int width,
                        int precision, int size)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    for (int i = 0; str[i]; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            buffer[count++] = '\\';
            buffer[count++] = 'x';
            buffer[count++] = "0123456789ABCDEF"[str[i] / 16];
            buffer[count++] = "0123456789ABCDEF"[str[i] % 16];
        }
        else
        {
            buffer[count++] = str[i];
        }
    }

    return (handle_write_char(buffer, count, flags, width, precision, size));
}
