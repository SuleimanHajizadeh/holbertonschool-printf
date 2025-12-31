#include "main.h"

/**
 * print_char - çap edir bir xarakteri
 * @c: çap ediləcək xarakter
 * Return: çap edilmiş xarakter sayı (1)
 */
int print_char(char c)
{
    return write(1, &c, 1);
}

/**
 * print_string - çap edir stringi
 * @s: string
 * Return: çap edilmiş xarakter sayı
 */
int print_string(char *s)
{
    int count = 0;

    if (!s)
        s = "(null)"; /* NULL pointer üçün */

    while (*s)
    {
        write(1, s, 1);
        s++;
        count++;
    }

    return count;
}

/**
 * _printf - əsas printf funksiyası
 * @format: format string
 * Return: çap edilmiş xarakterlərin sayı
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *str;
    char c;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* növbəti simvola keç */
            if (*format == 'c')
            {
                c = va_arg(args, int);
                count += print_char(c);
            }
            else if (*format == 's')
            {
                str = va_arg(args, char *);
                count += print_string(str);
            }
            else if (*format == '%')
            {
                count += print_char('%');
            }
            else
            {
                /* tanınmayan format üçün, sadəcə % və simvolu çap et */
                count += print_char('%');
                count += print_char(*format);
            }
        }
        else
        {
            count += print_char(*format);
        }
        format++;
    }

    va_end(args);
    return count;
}

