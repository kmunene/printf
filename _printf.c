#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf all the functions
 * @format: format specifier fo the printf.
 * Return: Printed characters
 */
int _printf(const char *format, ...)
{
	int zoo, print = 0, printed_characters = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (zoo = 0; format && format[zoo] != '\0'; zoo++)
	{
		if (format[zoo] != '%')
		{
			buffer[buff_ind++] = format[zoo];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[zoo], 1);*/
			printed_characters++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &zoo);
			width = get_width(format, &zoo, list);
			precision = get_precision(format, &zoo, list);
			size = get_size(format, &zoo);
			++zoo;
			print = handle_print(format, &zoo, list, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			printed_characters += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_characters);
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array of characters.
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
