#include "main.h"

/**
 * print_unsigned - prints an unsigned number in given base
 * @n: number to print
 * @base: base to print in (10, 8, 16)
 * @uppercase: 1 if hex should be uppercase
 * @buffer: buffer to store output
 * @buf_index: index in buffer
 * @count: total chars printed
 * Return: updated buffer index
 */
int print_unsigned(unsigned int n, int base, int uppercase,
                   char *buffer, int *buf_index, int *count)
{
    char *digits;
    char temp[32];
    int i;

    digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n == 0)
        return print_char('0', buffer, buf_index, count);

    i = 0;
    while (n)
    {
        temp[i] = digits[n % base];
        n /= base;
        i++;
    }

    /* print in reverse order */
    i--;
    while (i >= 0)
    {
        *buf_index = print_char(temp[i], buffer, buf_index, count);
        i--;
    }

    return (*buf_index);
}
