#include "main.h"
#include <unistd.h>
#include <stdint.h>

/**
 * print_pointer - Prints a pointer address in hexadecimal
 * @ptr: pointer to print
 * @buffer: local buffer
 * @buf_index: index in buffer
 * @count: total characters printed
 *
 * Return: updated buffer index
 */
int print_pointer(void *ptr, char *buffer, int *buf_index, int *count)
{
    unsigned long addr;
    char hex_digits[] = "0123456789abcdef";
    char tmp[32];
    int i = 0, j;

    if (!ptr)
        return (print_string("(nil)", buffer, buf_index, count));

    addr = (uintptr_t)ptr;

    /* build hex string in reverse */
    while (addr > 0)
    {
        tmp[i++] = hex_digits[addr % 16];
        addr /= 16;
    }

    /* add "0x" prefix */
    *buf_index = print_char('0', buffer, buf_index, count);
    *buf_index = print_char('x', buffer, buf_index, count);

    /* print reversed hex string */
    for (j = i - 1; j >= 0; j--)
        *buf_index = print_char(tmp[j], buffer, buf_index, count);

    return (*buf_index);
}
