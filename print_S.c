#include "main.h"

int print_S(char *s, char *buffer, int *buf_index)
{
    int i, len;
    char hex[] = "0123456789ABCDEF";

    len = 0;
    if (!s)
        s = "(null)";

    for (i = 0; s[i]; i++)
    {
        if (s[i] < 32 || s[i] >= 127)
        {
            print_char('\\', buffer, buf_index);
            print_char('x', buffer, buf_index);
            print_char(hex[(s[i] >> 4) & 0xF], buffer, buf_index);
            print_char(hex[s[i] & 0xF], buffer, buf_index);
            len += 4;
        }
        else
        {
            print_char(s[i], buffer, buf_index);
            len++;
        }
    }
    return (len);
}
