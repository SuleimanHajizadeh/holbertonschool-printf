#include "main.h"
#include <stdio.h>

// Prototype for _printf_custom
int _printf_custom(const char *format, ...);

int main(void)
{
        unsigned int i;
        i = _printf_custom("Char: %c Str: %upper\n", 'c', "salam");
        printf("Count: %d\n", i);
        return (0);
}
