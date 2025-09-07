#include "main.h"

int print_number(long n, char *buffer, int *buf_index)
{
    unsigned long num;
    int len;

    len = 0;
    if (n < 0)
    {
        print_char('-', buffer, buf_index);
        num = -n;
        len = 1;
    }
    else
        num = n;

    if (num / 10)
        len += print_number(num / 10, buffer, buf_index);

    print_char((num % 10) + '0', buffer, buf_index);
    return (len + 1);
}
