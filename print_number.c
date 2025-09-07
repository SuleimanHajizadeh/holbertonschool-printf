#include "main.h"

int print_number(int n, char *buffer, int *buf_index, int *count)
{
    unsigned int num;
    if (n < 0)
    {
        *buf_index = print_char('-', buffer, buf_index, count);
        num = -n;
    }
    else
        num = n;

    if (num / 10)
        *buf_index = print_number(num / 10, buffer, buf_index, count);

    *buf_index = print_char((num % 10) + '0', buffer, buf_index, count);

    return (*buf_index);
}
