#include "main.h"

/**
 * _rev_assign - reverse copy string
 */
void _rev_assign(char *buff, char *value)
{
    int len, i, j;

    len = _strlen(value);
    i = 0;
    j = len - 1;
    while (j >= 0)
    {
        buff[i] = value[j];
        i++;
        j--;
    }
}
