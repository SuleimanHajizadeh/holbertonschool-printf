else if (format[i + 1] == 'u')
    count += print_unsigned(va_arg(args, unsigned int), 10, 0);
else if (format[i + 1] == 'o')
    count += print_unsigned(va_arg(args, unsigned int), 8, 0);
else if (format[i + 1] == 'x')
    count += print_unsigned(va_arg(args, unsigned int), 16, 0);
else if (format[i + 1] == 'X')
    count += print_unsigned(va_arg(args, unsigned int), 16, 1);
