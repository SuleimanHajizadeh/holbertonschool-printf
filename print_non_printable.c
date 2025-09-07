#include "main.h"

int print_non_printable(char *s, char *buffer, int *buf_index, int *count)
{
    int i, c;
    char hex[] = "0123456789ABCDEF";

    if (!s)
        s = "(null)";
    i = 0;
    while (s[i])
    {
        c = s[i];
        if (c < 32 || c >= 127)
        {
            *buf_index = print_char('\\', buffer, buf_index, count);
            *buf_index = print_char('x', buffer, buf_index, count);
            *buf_index = print_char(hex[c / 16], buffer, buf_index, count);
            *buf_index = print_char(hex[c % 16], buffer, buf_index, count);
        }
        else
            *buf_index = print_char(c, buffer, buf_index, count);
        i++;
    }
    return (*buf_index);
}
