#include "main.h"

int print_S(char *s, char *buffer, int *buf_index, int *count)
{
    int i;
    char hex[3];

    if (!s)
        s = "(null)";

    for (i = 0; s[i]; i++)
    {
        if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
        {
            *buf_index = print_char('\\', buffer, buf_index, count);
            *buf_index = print_char('x', buffer, buf_index, count);
            hex[0] = "0123456789ABCDEF"[s[i] / 16];
            hex[1] = "0123456789ABCDEF"[s[i] % 16];
            hex[2] = '\0';
            *buf_index = print_char(hex[0], buffer, buf_index, count);
            *buf_index = print_char(hex[1], buffer, buf_index, count);
        }
        else
            *buf_index = print_char(s[i], buffer, buf_index, count);
    }

    return (*buf_index);
}
