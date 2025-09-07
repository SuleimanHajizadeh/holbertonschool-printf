#include "main.h"

int print_string(char *s, char *buffer, int *buf_index)
{
    int i;

    if (!s)
        s = "(null)";

    for (i = 0; s[i]; i++)
        print_char(s[i], buffer, buf_index);

    return (i);
}
