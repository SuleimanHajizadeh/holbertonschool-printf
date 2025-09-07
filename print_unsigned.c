#include "main.h"

/**
 * print_unsigned - prints an unsigned int in any base
 * @n: number to print
 * @base: base to convert to (8, 10, 16)
 * @uppercase: 1 if uppercase hex, 0 if lowercase
 *
 * Return: number of characters printed
 */
int print_unsigned(unsigned int n, int base, int uppercase)
{
    char buffer[50];
    char *digits;
    int i = 0, count = 0;

    digits = (uppercase) ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n == 0)
        return (print_char('0'));

    while (n > 0)
    {
        buffer[i++] = digits[n % base];
        n /= base;
    }

    while (i--)
        count += print_char(buffer[i]);

    return (count);
}
