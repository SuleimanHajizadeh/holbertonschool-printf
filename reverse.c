#include "main.h"

int _strlen(char *s)
{
    int count = 0;
    while (s[count]) count++;
    return count;
}

char *_reverse(char *s, int n)
{
    int i, aux;
    n--;
    for (i = 0; i <= n; i++, n--)
    {
        aux = s[i];
        s[i] = s[n];
        s[n] = aux;
    }
    return s;
}
