#include "main.h"
/**
 * _printf - Print function
 * @format: format
 * Return: Printed chars
 */
void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0, int flags, width, precision, size, buff_ind = 0;
	va_list ap;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(ap, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, ap);
			precision = get_precision(format, &i, ap);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, ap, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(ap);
	return (printed_chars);
}
/**
 * print_buffer - Prints the content of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: index at which to add the next char, represents the length.
 */
void print_buffer(char buffer[]; int *buff_ind)
{
	if(*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
