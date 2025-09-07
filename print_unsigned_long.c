#include "main.h"

int print_unsigned_long(unsigned long n, int base, int uppercase,
                        char *buffer, int *buf_index, int *count)
{
    char digits[] = "0123456789abcdef";
    char digits_upper[] = "0123456789ABCDEF";
    char tmp[65];
    int i = 0, j;

    if (n == 0)
        return print_char('0', buffer, buf_index, count);

    while (n > 0)
    {
        tmp[i++] = uppercase ? digits_upper[n % base] : digits[n % base];
        n /= base;
    }

    for (j = i - 1; j >= 0; j--)
        *buf_index = print_char(tmp[j], buffer, buf_index, count);

    return (*buf_index);
}
