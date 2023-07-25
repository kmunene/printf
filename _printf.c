#include "main.h"
<<<<<<< HEAD

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
=======
void print_buffer(char buffer[], int *buff_ind);

/**
 * custom_printf - Custom implementation of printf function.
 * @format: The format string.
 * Return: Number of printed characters.
 */
int custom_printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);

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
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;

printed = handle_print(format, &i, list, buffer, flags, width,
precision, size);

if (printed == -1)
return (-1);

printed_chars += printed;
}
}

print_buffer(buffer, &buff_ind);
va_end(list);

return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists.
 * @buffer: Array of characters.
 * @buff_ind: Index at which to add the next character, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
}
