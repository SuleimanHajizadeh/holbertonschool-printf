#include "main.h"

int print_char(char c, char *buffer, int *buf_index, int *count)
{
    buffer[*buf_index] = c;
    (*buf_index)++;
    (*count)++;
    if (*buf_index == 1024)
    {
        write(1, buffer, *buf_index);
        *buf_index = 0;
    }
    return (*buf_index);
}

int print_string(char *s, char *buffer, int *buf_index, int *count)
{
    int i;
    if (!s)
        s = "(null)";
    i = 0;
    while (s[i])
    {
        *buf_index = print_char(s[i], buffer, buf_index, count);
        i++;
    }
    return (*buf_index);
}
