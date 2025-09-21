#include "main.h"
#include <stdlib.h>

int _abs(int n)
{
    return n < 0 ? -n : n;
}

char *_itoa(int value, int base)
{
    static char buffer[1024];
    int i = 0, sign = value < 0 && base == 10 ? -1 : 0;
    unsigned int n = sign ? -value : value;

    if (value == 0)
        buffer[i++] = '0';

    while (n)
    {
        int r = n % base;
        buffer[i++] = (r > 9) ? r - 10 + 'A' : r + '0';
        n /= base;
    }

    if (sign)
        buffer[i++] = '-';

    buffer[i] = '\0';
    return _reverse(buffer, i);
}

char *_utoa(unsigned int value, unsigned int base)
{
    static char buffer[1024];
    int i = 0;
    if (value == 0)
        buffer[i++] = '0';
    while (value)
    {
        int r = value % base;
        buffer[i++] = (r > 9) ? r - 10 + 'A' : r + '0';
        value /= base;
    }
    buffer[i] = '\0';
    return _reverse(buffer, i);
}

char *_lcutoa(unsigned int value, unsigned int base)
{
    char *str = _utoa(value, base);
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    return str;
}
