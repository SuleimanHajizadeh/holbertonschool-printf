#include "main.h"

int print_string(char *s)
{
    int count = 0;

    if (!s)
        s = "(null)";

    while (*s)
    {
        count += _putchar(*s);
        s++;
    }
    return (count);
}
