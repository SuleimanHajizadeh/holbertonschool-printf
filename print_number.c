#include "main.h"

/**
 * print_number - prints an integer
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	char buffer[12];
	int i = 0, len = 0;
	unsigned int num;

	if (n == 0)
		return (write(1, "0", 1));

	if (n < 0)
	{
		len += write(1, "-", 1);
		num = -n;
	}
	else
	{
		num = n;
	}

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}

	while (i--)
		len += write(1, &buffer[i], 1);

	return (len);
}
