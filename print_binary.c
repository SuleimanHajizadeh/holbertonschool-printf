#include "main.h"

int print_binary(unsigned int n, char *buffer, int *buf_index, int *count)
{
    if (n / 2)
        *buf_index = print_binary(n / 2, buffer, buf_index, count);

    *buf_index = print_char(n % 2 + '0', buffer, buf_index, count);

    return (*buf_index);
}
