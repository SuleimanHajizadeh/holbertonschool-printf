#include "main.h"

int print_number(int n, flags_t f, char *buffer, int *buf_index, int *count)
{
    unsigned int num;
    if (n < 0)
    {
        buffer[*buf_index] = '-';
        (*buf_index)++;
        (*count)++;
        num = -n;
    }
    else
    {
        num = n;
        if (f.plus)
        {
            buffer[*buf_index] = '+';
            (*buf_index)++;
            (*count)++;
        }
        else if (f.space)
        {
            buffer[*buf_index] = ' ';
            (*buf_index)++;
            (*count)++;
        }
    }

    unsigned int div = 1000000000;
    int started = 0;
    for (; div; div /= 10)
    {
        int digit = num / div;
        if (digit || started || div == 1)
        {
            buffer[*buf_index] = digit + '0';
            (*buf_index)++;
            (*count)++;
            started = 1;
        }
        num %= div;
    }
    return *buf_index;
}
