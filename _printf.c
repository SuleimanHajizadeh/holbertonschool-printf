#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @s: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *s)
{
        int len = 0;

        if (!s)
                s = "(null)";

        while (s[len])
        {
                _putchar(s[len]);
                len++;
        }
        return (len);
}

/**
 * handle_format - handles format specifiers
 * @format: format character
 * @args: argument list
 *
 * Return: number of characters printed
 */
int handle_format(const char format, va_list args)
{
        int count = 0;

        if (format == 'c')
                count += _putchar(va_arg(args, int));
        else if (format == 's')
                count += print_string(va_arg(args, char *));
        else if (format == '%')
                count += _putchar('%');
        else
        {
                count += _putchar('%');
                count += _putchar(format);
        }
        return (count);
}

/**
 * _printf - custom printf function (Task 0)
 * @format: format string
 *
 * Return: number of characters printed, or -1 on error
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
                        if (!*format)
                        {
                                va_end(args);
                                return (-1);
                        }
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

