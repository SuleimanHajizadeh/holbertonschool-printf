#include "main.h"

int print_unsigned(unsigned int n, int base, int uppercase, flags_t f,
                   char *buffer, int *buf_index, int *count)
{
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (f.hash)
    {
        if (base == 8)
        {
            buffer[*buf_index] = '0';
            (*buf_index)++;
            (*count)++;
        }
        else if (base == 16)
        {
            buffer[*buf_index] = '0';
            (*buf_index)++;
            buffer[*buf_index] = uppercase ? 'X' : 'x';
            (*buf_index)++;
            (*count) += 2;
        }
    }

    unsigned int div = 1;
    while (div <= n / base)
        div *= base;

    for (; div; div /= base)
    {
        int digit = n / div;
        buffer[*buf_index] = digits[digit];
        (*buf_index)++;
        (*count)++;
        n %= div;
    }

    return *buf_index;
}
