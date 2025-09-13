#include "main.h"

int print_char(char c, char *buffer, int *buf_index)
{
    buffer[*buf_index] = c;
    (*buf_index)++;
    if (*buf_index == 1024)
    {
        write(1, buffer, 1024);
        *buf_index = 0;
    }
    return 1;
}

int print_string(char *s, char *buffer, int *buf_index)
{
    int i = 0, count = 0;
    if (!s)
        s = "(null)";
    while (s[i])
    {
        count += print_char(s[i], buffer, buf_index);
        i++;
    }
    return count;
}

int print_number(int n, char *buffer, int *buf_index, flags_t f)
{
    unsigned int num;
    int count = 0, div = 1000000000, started = 0;

    if (n < 0)
    {
        count += print_char('-', buffer, buf_index);
        num = -n;
    }
    else
    {
        num = n;
        if (f.plus)
            count += print_char('+', buffer, buf_index);
        else if (f.space)
            count += print_char(' ', buffer, buf_index);
    }

    while (div > 0)
    {
        int digit = num / div;
        if (digit || started || div == 1)
        {
            count += print_char(digit + '0', buffer, buf_index);
            started = 1;
        }
        num %= div;
        div /= 10;
    }
    return count;
}
