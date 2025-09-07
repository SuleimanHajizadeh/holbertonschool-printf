#include "main.h"

int print_number(int n, char *buffer, int *buf_index, int *count)
{
    unsigned int num;
    int len = 0;

    if (n < 0)
    {
        print_char('-', buffer, buf_index, count);
        num = -n;
        len++;
    }
    else
        num = n;

    if (num / 10)
        len += print_number(num / 10, buffer, buf_index, count);
    print_char((num % 10) + '0', buffer, buf_index, count);
    return (len + 1);
}
