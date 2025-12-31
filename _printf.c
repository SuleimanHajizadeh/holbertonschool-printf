#include "main.h"

/**
 * print_char - Writes a single character to stdout
 * @c: Character to print
 * Return: 1
 */
int print_char(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - Writes a string to stdout
 * @s: String to print
 * Return: Number of characters printed
 */
int print_string(char *s)
{
    int len = 0;

    if (!s)
        s = "(null)";

    while (*s)
    {
        write(1, s, 1);
        s++;
        len++;
    }
    return (len);
}

/**
 * _printf - Custom printf function (task 0)
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, len = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])  /* string sonunda % varsa, heç nə çap et */
                break;

            if (format[i] == 'c')
                len += print_char(va_arg(args, int));
            else if (format[i] == 's')
                len += print_string(va_arg(args, char *));
            else if (format[i] == '%')
                len += print_char('%');
            else
            {
                /* Unknown specifier: print as-is */
                len += print_char('%');
                len += print_char(format[i]);
            }
        }
        else
            len += print_char(format[i]);
        i++;
    }

    va_end(args);
    return (len);
}

