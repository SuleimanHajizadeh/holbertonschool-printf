#include "main.h"
#include <unistd.h>

int print_string(char *s, char *buffer, int *buf_index, int *count)
{
    int i = 0;
    if (!s)
        s = "(null)";
    for (; s[i]; i++)
        print_char(s[i], buffer, buf_index, count);
    return (i);
}
