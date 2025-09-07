#include "main.h"

/**
 * print_string - prints a string
 * @s: string to print
 * Return: number of characters printed
 */
int print_string(char *s)
{
    int i, len = 0;

    if (!s)
        s = "(null)";

    for (i = 0; s[i]; i++)
        len += write(1, &s[i], 1);

    return (len);
}
