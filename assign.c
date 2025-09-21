#include "main.h"

int _assign(char *buff, int count, char *value)
{
    int i = 0;
    while (value[i])
        buff[i++] = value[i++];
    return count + _strlen(value);
}

int _rev_assign(char *buff, int count, char *value)
{
    int len = _strlen(value), i;
    for (i = 0; i < len; i++)
        buff[i] = value[len - i - 1];
    return count + len;
}
