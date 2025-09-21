#include "main.h"

func_ptr_t check_prtr(char specifier)
{
    ptr_ch arg_ptr[] = {
        {"d", func_d}, {"i", func_i}, {"u", func_u},
        {"o", func_o}, {"x", func_x}, {"X", func_X},
        {"c", func_c}, {"s", func_s}, {"%", func_ptg},
        {"b", func_b}, {"r", func_r}, {"R", func_R},
        {NULL, NULL}
    };

    for (int j = 0; arg_ptr[j].c; j++)
        if (specifier == *arg_ptr[j].c)
            return arg_ptr[j].f;

    return NULL;
}
