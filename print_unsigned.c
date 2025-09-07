#include "main.h"

int print_unsigned(unsigned int n, int base, int uppercase,
                   char *buffer, int *buf_index, int *count)
{
    char *digits;
    unsigned int div;
    int i, started = 0;
    char temp[32];

    digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n == 0)
        return print_char('0', buffer, buf_index, count);

    for (i = 0; n; i++)
    {
        temp[i] = digits[n % base];
        n /= base;
    }

    for (--i; i >= 0; i--)
        *buf_index = print_char(temp[i], buffer, buf_index, count);

    return (*buf_index);
}
