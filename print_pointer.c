#include "main.h"

/**
 * print_pointer - prints the value of a pointer in hexadecimal
 * @ptr: pointer to print
 * @buffer: local buffer of 1024 chars
 * @buf_index: current index in the buffer
 * @count: total number of characters printed
 *
 * Return: updated buf_index
 */
int print_pointer(void *ptr, char *buffer, int *buf_index, int *count)
{
    unsigned long n = (unsigned long)ptr;

    /* print leading "0x" */
    *buf_index = print_char('0', buffer, buf_index, count);
    *buf_index = print_char('x', buffer, buf_index, count);

    /* print pointer value in lowercase hex */
    if (n == 0)
        *buf_index = print_char('0', buffer, buf_index, count);
    else
        *buf_index = print_unsigned(n, 16, 0, buffer, buf_index, count);

    return (*buf_index);
}
