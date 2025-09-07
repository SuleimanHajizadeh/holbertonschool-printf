#include "main.h"

int print_pointer(void *ptr, char *buffer, int *buf_index, int *count)
{
    unsigned long addr = (unsigned long)ptr;

    *buf_index = print_char('0', buffer, buf_index, count);
    *buf_index = print_char('x', buffer, buf_index, count);

    if (addr == 0)
        *buf_index = print_char('0', buffer, buf_index, count);
    else
        *buf_index = print_unsigned_long(addr, 16, 0, buffer, buf_index, count);

    return (*buf_index);
}
