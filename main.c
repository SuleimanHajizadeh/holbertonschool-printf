#include "main.h"
#include <stdio.h>int main(void)
{
        unsigned int i;        i = _printf_custom("Char: %c Str: %upper\n", 'c', "salam");
        printf("Count: %d\n", i);
        return (0);
}
