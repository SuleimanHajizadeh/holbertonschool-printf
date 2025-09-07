#include "main.h"

int print_string(char *s, char *buffer, int *buf_index, int *count)
{
    int i;

    if (s == NULL)
        s = "(null)";

    for (i = 0; s[i] != '\0'; i++)
    {
        buffer[*buf_index] = s[i];
        (*buf_index)++;
        (*count)++;

        if (*buf_index == 1024)
        {
            write(1, buffer, *buf_index);
            *buf_index = 0;
        }
    }

    return (*buf_index);
}
