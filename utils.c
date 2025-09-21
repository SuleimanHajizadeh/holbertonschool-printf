#include "main.h"

int _strlen(char *s)
{
    int len = 0;
    while (s[len])
        len++;
    return len;
}

char *_reverse(char *s, int n)
{
    int i, tmp;
    for (i = 0; i < n / 2; i++)
    {
        tmp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = tmp;
    }
    return s;
}

void _strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void _rev_ptr(char *str)
{
    int len = _strlen(str), i, tmp;
    for (i = 0; i < len / 2; i++)
    {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}
