#include "main.h"
#include <stdlib.h>

int _abs(int n)
{
    return (n < 0 ? -n : n);
}

char *_itoa(int value, int base)
{
    static char buffer[1024];
    int n = _abs(value);
    int i = 0;

    if (base < 2 || base > 32)
        exit(1);

    while (n)
    {
        int r = n % base;
        buffer[i++] = (r >= 10) ? 65 + (r - 10) : 48 + r;
        n /= base;
    }

    if (i == 0)
        buffer[i++] = '0';

    if (value < 0 && base == 10)
        buffer[i++] = '-';

    buffer[i] = '\0';
    return _reverse(buffer, i);
}
