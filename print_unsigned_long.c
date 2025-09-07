#include "main.h"

int print_unsigned_long(unsigned long n, int base, int uppercase,
                        char *buffer, int *buf_index)
{
    char digits[] = "0123456789abcdef";
    char digits_up[] = "0123456789ABCDEF";
    int len = 0;
    unsigned long div;

    div = n / base;
    if (div)
        len += print_unsigned_long(div, base, uppercase, buffer, buf_index);

    print_char(uppercase ? digits_up[n % base] : digits[n % base],
               buffer, buf_index);
    return (len + 1);
}
