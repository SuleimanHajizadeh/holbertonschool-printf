#include "main.h"

int print_unsigned(unsigned int n, int base, int uppercase,
                   char *buffer, int *buf_index, int *count)
{
    char digits[] = "0123456789abcdef";
    char DIGITS[] = "0123456789ABCDEF";
    unsigned int div;
    int i, started;

    div = 1;
    while (div <= n / base)
        div *= base;

    started = 0;
    while (div)
    {
        if (uppercase)
            i = DIGITS[n / div];
        else
            i = digits[n / div];
        *buf_index = print_char(i, buffer, buf_index, count);
        n %= div;
        div /= base;
    }
    if (!started)
        *buf_index = print_char('0', buffer, buf_index, count);

    return (*buf_index);
}
