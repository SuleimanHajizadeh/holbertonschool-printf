for (i = 0; format[i] != '\0'; i++)
{
    if (format[i] == '%')
    {
        i++; /* move to the specifier */

        if (format[i] == 'p')
            buf_index = print_pointer(va_arg(args, void *), buffer, &buf_index, &count);
        else if (format[i] == 's')
            buf_index = print_string(va_arg(args, char *), buffer, &buf_index, &count);
        /* ... other specifiers ... */
        else
            buf_index = print_char(format[i], buffer, &buf_index, &count);
    }
    else
    {
        buf_index = print_char(format[i], buffer, &buf_index, &count);
    }
}
