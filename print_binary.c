#include "main.h"
#include <unistd.h>

int print_binary(unsigned int n, char *buffer, int *buf_index, int *count)
{
    if (n > 1)
        print_binary(n / 2, buffer, buf_index, count);

    buffer[*buf_index] = (n % 2) + '0';
    (*buf_index)++;
    (*count)++;

    if (*buf_index == 1024)
    {
        write(1, buffer, *buf_index);
        *buf_index = 0;
    }

    return (*buf_index);
}
