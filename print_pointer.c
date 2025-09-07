#include "main.h"

int print_pointer(void *p, char *buffer, int *buf_index, int *count)
{
    unsigned long addr = (unsigned long)p;
    int len = 0;

    print_char('0', buffer, buf_index, count);
    print_char('x', buffer, buf_index, count);
    len += 2;
    len += print_unsigned(addr, 16, 0, buffer, buf_index, count);
    return (len);
}
