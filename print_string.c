#include "main.h"

/**
 * print_string - prints a string to buffer
 * @s: string to print
 * @buffer: local buffer
 * @buf_index: current buffer index
 * @count: total characters printed
 *
 * Return: updated buffer index
 */
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
