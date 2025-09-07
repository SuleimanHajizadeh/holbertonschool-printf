#include "main.h"

int print_pointer(void *p, char *buffer, int *buf_index)
{
    unsigned long addr;
    int len;

    addr = (unsigned long)p;
    len = 0;

    print_char('0', buffer, buf_index);
    print_char('x', buffer, buf_index);
    len += 2;

    len += print_unsigned(addr, 16, 0, buffer, buf_index);
    return (len);
}
