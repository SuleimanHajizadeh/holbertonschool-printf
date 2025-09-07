#include "main.h"

int print_binary(unsigned int n, char *buffer, int *buf_index, int *count)
{
    int bin[32];
    int i, j;

    i = 0;
    if (n == 0)
        *buf_index = print_char('0', buffer, buf_index, count);
    while (n > 0)
    {
        bin[i] = n % 2;
        n /= 2;
        i++;
    }
    for (j = i - 1; j >= 0; j--)
        *buf_index = print_char('0' + bin[j], buffer, buf_index, count);

    return (*buf_index);
}
