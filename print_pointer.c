#include "main.h"

int print_pointer(void *ptr, char *buffer, int *buf_index, int *count)
{
    unsigned long addr;

    if (!ptr)
        return print_string("(nil)", buffer, buf_index, count);

    addr = (unsigned long)ptr;
    *buf_index = print_string("0x", buffer, buf_index, count);
    *buf_index = print_unsigned(addr, 16, 0, buffer, buf_index, count);

    return (*buf_index);
}
