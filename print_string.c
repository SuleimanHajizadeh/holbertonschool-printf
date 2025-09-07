#include "main.h"
#include <stddef.h>
#include <string.h>

int print_string(char *s, char *buffer, int *buf_index, int *count)
{
    if (!s)
        s = "(null)";
    for (int i = 0; s[i]; i++)
    {
        buffer[*buf_index] = s[i];
        (*buf_index)++;
        (*count)++;
    }
    return *buf_index;
}
