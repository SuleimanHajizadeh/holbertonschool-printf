#include "main.h"

/**
 * handle_print - Handles specifiers
 */
int handle_print(const char *fmt, int *i, va_list list,
    char buffer[], int flags, int width, int precision, int size)
{
    int j;
    fmt_t fmt_types[] = {
        {'c', print_char}, {'s', print_string}, {'%', print_percent},
        {'d', print_number}, {'i', print_number},
        {'\0', NULL}
    };

    for (j = 0; fmt_types[j].fmt != '\0'; j++)
        if (fmt[*i] == fmt_types[j].fmt)
            return (fmt_types[j].fn(list, buffer, flags, width, precision, size));

    return (-1);
}
