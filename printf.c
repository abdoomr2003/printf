#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)

{
	int j, print = 0, print_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list ls;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(ls, format);
	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[j], 1);*/
			print_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			printed = handle_print(format, &j, list, buff,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			print_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (print_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
