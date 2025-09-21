#include "main.h"

/**
 * get_flags - computes active flags for a format specifier
 * @format: format string
 * @i: pointer to current index
 * Return: flag integer
 */
int get_flags(const char *format, int *i)
{
    int j, curr_i;
    int flags = 0;
    const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};

    curr_i = *i + 1;
    for (; format[curr_i] != '\0'; curr_i++)
    {
        for (j = 0; FLAGS_CHARS[j] != '\0'; j++)
        {
            if (format[curr_i] == FLAGS_CHARS[j])
            {
                flags |= FLAGS_VALUES[j];
                break;
            }
        }
        if (FLAGS_CHARS[j] == '\0')
            break;
    }

    *i = curr_i - 1;
    return (flags);
}

/**
 * is_digit - checks if a character is a digit
 * @c: character
 * Return: 1 if digit, 0 otherwise
 */
int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}
