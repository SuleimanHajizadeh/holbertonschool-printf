#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, count = 0;

    va_start(args, format);

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 'c')
                count += print_char(va_arg(args, int));
            else if (format[i + 1] == 's')
                count += print_string(va_arg(args, char *));
            else if (format[i + 1] == 'd' || format[i + 1] == 'i')
                count += print_number(va_arg(args, int));
            else if (format[i + 1] == 'b')
                count += print_binary(va_arg(args, unsigned int));
            else if (format[i + 1] == '%')
                count += print_char('%');
            else
                count += print_char('%');
            i++;
        }
        else
        {
            count += print_char(format[i]);
        }
    }

    va_end(args);
    return (count);
}
