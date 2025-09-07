#include "main.h"

/**
 * print_binary - Prints an unsigned int in binary
 * @b: The list of arguments
 *
 * Return: The number of characters printed
 */
int print_binary(va_list b)
{
	unsigned int num = va_arg(b, unsigned int);
	int count = 0;
	int i;
	char binary[32];

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	for (i = 0; num > 0; i++)
	{
		binary[i] = (num % 2) + '0';
		num /= 2;
	}

	while (--i >= 0)
	{
		_putchar(binary[i]);
		count++;
	}

	return (count);
}
