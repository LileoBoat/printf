#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"

/**
 * _printf - prints anything with format
 * @format: list of types of arguments passed to the function
 *
 * Return: number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list args;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += _putchar(va_arg(args, int));
			else if (format[i] == 's')
				count += _puts(va_arg(args, char *));
			else if (format[i] == '%')
				count += _putchar('%');
			else
				return (-1);
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
