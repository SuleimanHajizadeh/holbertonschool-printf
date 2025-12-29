#include "main.h"
#include <stdarg.h>

/**
 * _assign - copy value into buff safely
 */
void _assign(char *buff, char *value)
{
    int i, j;
    char temp;

    i = 0;
    j = 0;
    while (value[i])
    {
        temp = value[i];
        buff[j] = temp;
        i++;
        j++;
    }
}

/**
 * _strlen - returns length of string
 */
int _strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
