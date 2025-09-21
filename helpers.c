#include "main.h"

int _assign(char *buff, int count, char *value)
{
    for (int i = 0; value[i]; i++)
        buff[count++] = value[i];
    return count;
}

int _strlen(char *s)
{
    int len = 0;
    while (s[len]) len++;
    return len;
}

char *_reverse(char *s, int n)
{
    int i = 0, j = n - 1;
    char tmp;
    while (i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
    s[n] = '\0';
    return s;
}

char *_itoa(int value, int base)
{
    static char buffer[1024];
    int i = 0, is_neg = 0;
    unsigned int n;

    if (value < 0 && base == 10)
    {
        is_neg = 1;
        n = -value;
    }
    else
        n = value;

    do
    {
        int r = n % base;
        buffer[i++] = (r > 9) ? r - 10 + 'A' : r + '0';
        n /= base;
    } while (n);

    if (is_neg)
        buffer[i++] = '-';

    buffer[i] = '\0';
    _reverse(buffer, i);
    return buffer;
}

char *_utoa(unsigned int value, unsigned int base)
{
    static char buffer[1024];
    int i = 0;
    do
    {
        int r = value % base;
        buffer[i++] = (r > 9) ? r - 10 + 'A' : r + '0';
        value /= base;
    } while (value);

    buffer[i] = '\0';
    _reverse(buffer, i);
    return buffer;
}

char *_lcutoa(unsigned int value, unsigned int base)
{
    static char buffer[1024];
    int i = 0;
    do
    {
        int r = value % base;
        buffer[i++] = (r > 9) ? r - 10 + 'a' : r + '0';
        value /= base;
    } while (value);

    buffer[i] = '\0';
    _reverse(buffer, i);
    return buffer;
}

int _abs(int n)
{
    return (n < 0) ? -n : n;
}

void _strcpy(char *dest, char *src)
{
    for (int i = 0; src[i]; i++)
        dest[i] = src[i];
}

void _rev_ptr(char *str)
{
    int len = _strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

char *_rot13(char *str)
{
    char chs[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    for (int i = 0; str[i]; i++)
        for (int j = 0; chs[j]; j++)
            if (str[i] == chs[j])
            {
                str[i] = rot[j];
                break;
            }
    return str;
}
