/* main_test.c */
#include "main.h"

int main(void)
{
    _printf("Test: %d, %i, %u, %o, %x, %X, %c, %s, %%\n",
            42, -42, 3000, 255, 255, 255, 'A', "hello");
    _printf("Binary: %b\n", 5);
    _printf("Reverse: %r\n", "hello");
    _printf("ROT13: %R\n", "hello");
    return 0;
}
