#include "main.h"

int print_char(char c, char *buffer, int *buf_index, int *count)
{
    buffer[*buf_index] = c;
    (*buf_index)++;
    (*count)++;

    if (*buf_index == 1024)
    {
        write(1, buffer, 1024);
        *buf_index = 0;
    }

    return (*buf_index);
}
