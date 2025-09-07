#include "main.h"

int print_unsigned(unsigned int n, int base, int uppercase,
                   char *buffer, int *buf_index, int *count)
{
    char *digits;
    char tmp[32];
    int i = 0, j;

    digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n == 0)
        *buf_index = print_char('0', buffer, buf_index, count);

    while (n)
    {
        tmp[i++] = digits[n % base];
        n /= base;
    }

    for (j = i - 1; j >= 0; j--)
        *buf_index = print_char(tmp[j], buffer, buf_index, count);

    return (*buf_index);
}
