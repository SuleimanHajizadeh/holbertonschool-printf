#include "main.h"

int print_number(int n, flags_t f, char *buffer, int *buf_index, int *count)
{
    unsigned int num, div;
    int i, neg;

    neg = 0;
    if (n < 0)
    {
        neg = 1;
        num = -n;
    }
    else
        num = n;

    if (!neg)
    {
        if (f.plus)
            *buf_index = print_char('+', buffer, buf_index, count);
        else if (f.space)
            *buf_index = print_char(' ', buffer, buf_index, count);
    }
    else
        *buf_index = print_char('-', buffer, buf_index, count);

    div = 1000000000;
    i = 0;
    while (div > 0)
    {
        if (num / div)
            *buf_index = print_char('0' + (num / div) % 10, buffer, buf_index, count);
        div /= 10;
        i++;
    }
    if (i == 0)
        *buf_index = print_char('0', buffer, buf_index, count);

    return (*buf_index);
}
