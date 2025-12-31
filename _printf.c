#include "main.h"

/**
 * _putchar - Writes a single character to stdout
 * @c: Character to print
 * Return: 1
 */
int _putchar(char c)
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
        _putchar(*s);
        s++;
        len++;
    }
    return (len);
}

/**
 * handle_format - Handles format specifiers
 * @format: Format specifier
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int handle_format(const char format, va_list args)
{
    int count = 0;

    switch (format)
    {
    case 'c':
        count += _putchar(va_arg(args, int));
        break;
    case 's':
        count += print_string(va_arg(args, char *));
        break;
    case '%':
        count += _putchar('%');
        break;
    default:
        count += _putchar('%');
        count += _putchar(format);
        break;
    }
    return (count);
}

/**
 * _printf - Custom printf function (task 0)
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (!*format)  /* String sonunda % varsa, heç nə çap etmir */
                break;
            count += handle_format(*format, args);
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);
    return (count);
}

