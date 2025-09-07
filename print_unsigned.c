#include "main.h"
#include <unistd.h>

int print_unsigned(unsigned int n, int base, int uppercase,
                   char *buffer, int *buf_index, int *count)
{
    char digits[] = "0123456789abcdef";
    char upper_digits[] = "0123456789ABCDEF";
    char tmp[32];
    int i = 0;

    if (n == 0)
    {
        buffer[*buf_index] = '0';
        (*buf_index)++;
        (*count)++;
        if (*buf_index == 1024)
        {
            write(1, buffer, *buf_index);
            *buf_index = 0;
        }
        return (*buf_index);
    }

    while (n > 0)
    {
        tmp[i++] = uppercase ? upper_digits[n % base] : digits[n % base];
        n /= base;
    }

    while (i--)
    {
        buffer[*buf_index] = tmp[i];
        (*buf_index)++;
        (*count)++;
        if (*buf_index == 1024)
        {
            write(1, buffer, *buf_index);
            *buf_index = 0;
        }
    }

    return (*buf_index);
}
