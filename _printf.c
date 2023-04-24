#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints output according to a format
 * @format: format string containing directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
        int i = 0, count = 0;
        va_list args;

        va_start(args, format);

        while (format && format[i])
        {
                if (format[i] == '%')
                {
                        i++;
                        switch (format[i])
                        {
                                case 'c':
                                        count += putchar(va_arg(args, int));
                                        break;
                                case 's':
                                        count += printf("%s", va_arg(args, char *));
                                        break;
                                case '%':
                                        count += putchar('%');
                                        break;
                                default:
                                        count += putchar('%');
                                        count += putchar(format[i]);
                        }
                }
                else
                {
                        count += putchar(format[i]);
                }
                i++;
        }

        va_end(args);

        return (count);
}

