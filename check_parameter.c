#include "main.h"
#include <stdarg.h>

/* Example function pointer typedef */
typedef int (*func_ptr_t)(char *, int, va_list, int);

func_ptr_t check_prtr(char specifier)
{
    int i;
    struct param {
        char c;
        func_ptr_t f;
    } arg_ptr[] = {
        {'c', func_c},
        {'s', func_s},
        {'%', func_ptg},
        {0, NULL}
    };

    i = 0;
    while (arg_ptr[i].c)
    {
        if (arg_ptr[i].c == specifier)
            return (arg_ptr[i].f);
        i++;
    }
    return (NULL);
}
