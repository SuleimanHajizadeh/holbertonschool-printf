#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>void print_char(char c)
{
        write(1, &c, 1);
}unsigned int print_string(char *str)
{
        unsigned int i;        for (i = 0; str[i] != '\0'; i++);        write(1, str, i);
        return (i);
}char *to_upper(char *str)
{
        unsigned int i;
        char *upper;        for (i = 0; str[i] != '\0'; i++);        upper = malloc((i + 1) * sizeof(char));
        if (upper == NULL)
                return (NULL);
        for (i = 0; str[i] != '\0'; i++)
                if (str[i] >= 97 && str[i] <= 122)
                        upper[i] = str[i] - 32;
        upper[i] = '\0';
        return (upper);
}int _printf_custom(const char *format, ...)
{
        va_list args;
        unsigned int i, j;
        char *str;        j = 0;
        for (i = 0; format[i] != '\0'; i++)
        {
                if (format[i] == '%')
                {
                        if (format[i+1] == 'l' && format[i+2] == 'o' && format[i+3] == 'w' && format[i+4] == 'e' && format[i+5] == 'r')
                                j++;
                        else if (format[i+1] == 'i' && format[i+2] == 's' && format[i+3] == 'n' && format[i+4] == 'u' && format[i+5] == 'm' && format[i+6] == 'b' && format[i+7] == 'e' && format[i+8] == 'r')
                                j++;
                        else if (format[i+1] == 'i' && format[i+2] == 's' && format[i+3] == 'a' && format[i+4] == 'l' && format[i+5] == 'p' && format[i+6] == 'h' && format[i+7] == 'a')
                                j++;
                }
                                  }
        }
        va_start(args, format);        j = 0;
        for (i = 0; format[i] != '\0'; i++)
        {
                if (format[i] != '%')
                        print_char(format[i]), j++;
                else if (format[i+1] == 'c')
                        print_char((char) va_arg(args, int)), i++, j++;
                else if (format[i+1] == 's')
                        j += print_string(va_arg(args, char *)), i++;
                else if (format[i+1] == 'u' && format[i+2] == 'p' && format[i+3] == 'p' && format[i+4] == 'e' && format[i+5] == 'r')
                {
                        str = to_upper(va_arg(args, char *));
                        if (str == NULL)
                                continue;
                        j += print_string(str), i += 5;
                        free(str);
                }
        }        va_end(args);
        return (j);
}
