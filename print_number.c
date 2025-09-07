#include "main.h"
#include <unistd.h>

int print_number(int n, char *buffer, int *buf_index, int *count)
{
    unsigned int num;

    if (n < 0)
    {
        buffer[*buf_index] = '-';
        (*buf_index)++;
        (*count)++;

        if (*buf_index == 1024)
        {
            write(1, buffer, *buf_index);
            *buf_index = 0;
        }

        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
        print_number(num / 10, buffer, buf_index, count);

    buffer[*buf_index] = (num % 10) + '0';
    (*buf_index)++;
    (*count)++;

    if (*buf_index == 1024)
    {
        write(1, buffer, *buf_index);
        *buf_index = 0;
    }

    return (*buf_index);
}
