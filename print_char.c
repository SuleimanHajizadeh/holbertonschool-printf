#include "main.h"
#include <unistd.h>

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
