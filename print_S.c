#include "main.h"
#include <unistd.h>
#include <stddef.h>

/**
 * print_S - prints a string, replacing non-printable characters
 * with \xHH format (uppercase hex, always 2 chars)
 * @s: input string
 * @buffer: buffer array
 * @buf_index: pointer to buffer index
 * @count: pointer to printed characters count
 *
 * Return: updated buffer index
 */
int print_S(char *s, char *buffer, int *buf_index, int *count)
{
    char hex[] = "0123456789ABCDEF";
    unsigned char c;

    if (s == NULL)
        s = "(null)";

    while (*s)
    {
        c = (unsigned char)*s;
        if (c < 32 || c >= 127)
        {
            /* Print \x */
            buffer[(*buf_index)++] = '\\';
            buffer[(*buf_index)++] = 'x';
            (*count) += 2;

            if (*buf_index >= 1024)
            {
                write(1, buffer, *buf_index);
                *buf_index = 0;
            }

            /* Print two hex digits */
            buffer[(*buf_index)++] = hex[c / 16];
            buffer[(*buf_index)++] = hex[c % 16];
            (*count) += 2;
        }
        else
        {
            buffer[(*buf_index)++] = c;
            (*count)++;
        }

        if (*buf_index >= 1024)
        {
            write(1, buffer, *buf_index);
            *buf_index = 0;
        }
        s++;
    }
    return (*buf_index);
}
