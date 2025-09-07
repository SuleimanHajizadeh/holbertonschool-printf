#include "main.h"

int print_unsigned(unsigned int n, int base, int uppercase,
                   char *buffer, int *buf_index, int *count)
{
    char digits[] = "0123456789abcdef";
    char digits_up[] = "0123456789ABCDEF";
    unsigned int div = n / base;
    int len = 0;

    if (div)
        len += print_unsigned(div, base, uppercase, buffer, buf_index, count);
    print_char((uppercase ? digits_up[n % base] : digits[n % base]),
               buffer, buf_index, count);
    return (len + 1);
}
