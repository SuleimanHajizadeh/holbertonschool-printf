#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...);

/**
 * handle_format - handles format specifiers
 * @format: format character
 * @args: argument list
 *
 * Return: number of characters printed
 */
int handle_format(const char format, va_list args);

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1
 */
int _putchar(char c);

/**
 * print_string - prints a string
 * @s: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *s);
int print_int(int n);

#endif /* MAIN_H */

