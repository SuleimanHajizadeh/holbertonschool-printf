#include "main.h"

/**
 * handle_print - selects correct printing function
 * @fmt: format character
 * @args: arguments list
 * @buffer: buffer array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: number of characters printed
 */
int handle_print(const char fmt, va_list args, char buffer[],
                 int flags, int width, int precision, int size)
{
    int i, printed = 0;
    fmt_t fmt_types[] = {
        {'c', print_char}, {'s', print_string}, {'%', print_percent},
        {'d', print_int}, {'i', print_int}, {'b', print_binary},
        {'u', print_unsigned}, {'o', print_octal}, {'x', print_hex},
        {'X', print_HEX}, {'S', print_S}, {'p', print_pointer},
        {'\0', NULL}
    };

    for (i = 0; fmt_types[i].fmt != '\0'; i++)
    {
        if (fmt == fmt_types[i].fmt)
        {
            printed = fmt_types[i].fn(args, buffer, flags, width, precision, size);
            break;
        }
    }

    return (printed);
}
