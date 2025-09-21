#include "main.h"

/**
 * print_char_buffer - Writes a single character to the buffer
 * @c: character to be written
 * @buffer: buffer array
 * @buf_index: pointer to current index
 *
 * Return: Always 1
 */
int print_char_buffer(char c, char buffer[], int *buf_index)
{
    buffer[*buf_index] = c;
    (*buf_index)++;
    if (*buf_index == BUFF_SIZE)
    {
        write(1, buffer, *buf_index);
        *buf_index = 0;
    }
    return (1);
}
