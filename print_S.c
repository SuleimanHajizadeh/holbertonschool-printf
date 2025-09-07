#include "main.h"

int print_S(char *s, char *buffer, int *buf_index, int *count)
{
    int i, len = 0;
    if (!s)
        s = "(null)";

    for (i = 0; s[i]; i++)
    {
        if (s[i] < 32 || s[i] >= 127)
        {
            print_char('\\', buffer, buf_index, count);
            print_char('x', buffer, buf_index, count);
            char hex[] = "0123456789ABCDEF";
            print_char(hex[(s[i] >> 4) & 0xF], buffer, buf_index, count);
            print_char(hex[s[i] & 0xF], buffer, buf_index, count);
            len += 4;
        }
        else
            len += print_char(s[i], buffer, buf_index, count);
    }
    return (len);
}
