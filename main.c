#include "main.h"

int main(void)
{
    int a = 42;
    int *ptr = &a;

    _printf("Address of a: %p\n", ptr);
    _printf("NULL pointer: %p\n", NULL);

    return (0);
}
