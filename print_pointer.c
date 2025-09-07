#include "main.h"

int print_pointer(void *ptr, char *buffer, int *buf_index, int *count)
{
    unsigned long addr;

    if (ptr == NULL)
    {
        *buf_index = print_char('(', buffer, buf_index, count);
        *buf_index = print_char('n', buffer, buf_index, count);
        *buf_index = print_char('i', buffer, buf_index, count);
        *buf_index = print_char('l', buffer, buf_index, count);
        *buf_index = print_char(')', buffer, buf_index, count);
        return (*buf_index);
    }

    addr = (unsigned long)ptr;

    *buf_index = print_char('0', buffer, buf_index, count);
    *buf_index = print_char('x', buffer, buf_index, count);

    *buf_index = print_unsigned_long(addr, 16, 0, buffer, buf_index, count);

    return (*buf_index);
}
