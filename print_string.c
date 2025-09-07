#include "main.h"
#include <unistd.h>
#include <stddef.h>

int print_string(char *s, char *buffer, int *buf_index, int *count)
{
    if (s == NULL)
        s = "(null)";

    while (*s)
    {
        buffer[*buf_index] = *s++;
        (*buf_index)++;
        (*count)++;

        if (*buf_index == 1024)
        {
            write(1, buffer, *buf_index);
            *buf_index = 0;
        }
    }
    return (*buf_index);
}
