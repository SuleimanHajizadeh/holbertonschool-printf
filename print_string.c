#include "main.h"

int print_string(char *s, char *buffer, int *buf_index, int *count)
{
    int i;

    if (!s)
        s = "(null)";

    for (i = 0; s[i]; i++)
        *buf_index = print_char(s[i], buffer, buf_index, count);

    return (*buf_index);
}
