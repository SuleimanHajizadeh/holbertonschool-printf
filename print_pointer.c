#include "main.h"

/**
 * print_pointer - prints a pointer in full hexadecimal format
 * @ptr: pointer to print
 * @buffer: buffer of 1024 chars
 * @buf_index: pointer to current buffer index
 * @count: pointer to total characters printed
 *
 * Return: updated buffer index
 */
int print_pointer(void *ptr, char *buffer, int *buf_index, int *count)
{
    unsigned long n = (unsigned long)ptr;

    /* Print leading 0x */
    *buf_index = print_char('0', buffer, buf_index, count);
    *buf_index = print_char('x', buffer, buf_index, count);

    if (n == 0)
        *buf_index = print_char('0', buffer, buf_index, count);
    else
        *buf_index = print_unsigned(n, 16, 0, buffer, buf_index, count);

    return (*buf_index);
}
