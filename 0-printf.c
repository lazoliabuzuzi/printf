#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: the number of characters printed (excluding
 * the null byte used to end output to strings)
*/

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0;

	while (*format)
	{
		if (*format == '%')
			format++;

		if (*format == 'c')
		{
			int c = va_arg(args, int);

			putchar(c);
			count++;
		}
		else if (*format == 's')
		{
			char *s = va_arg(args, char *);

			while (*s)
			{
				putchar(*s);
				count++;
				s++;
			}
		}
		else if (*format == '%')
			putchar('%');
			count++;
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
