#include "main.h"

int print_char(char c, char *buffer, int *buf_index, int *count)
{
    buffer[*buf_index] = c;
    (*buf_index)++;
    (*count)++;
    return *buf_index;
}
