#include "main.h"
#include <unistd.h>

/**
 * print_char - add a character to buffer
 * @c: char to add
 * @buffer: local buffer
 * @buf_index: current buffer index
 * @count: total printed count
 *
 * Return: new buffer index
 */
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
