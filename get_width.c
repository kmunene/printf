#include "main.h"

/**
<<<<<<< HEAD
 * get_width - Cal the width for p
 * @format:  the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width of the string.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_d;
	int wid = 0;

	for (curr_d = *i + 1; format[curr_d] != '\0'; curr_d++)
	{
		if (is_digit(format[curr_d]))
		{
			wid *= 10;
			wid += format[curr_d] - '0';
		}
		else if (format[curr_d] == '*')
		{
			curr_d++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_d - 1;

	return (wid);
=======
 * get_width - This function calculates the width for printing
 * @format: Formatted strng containing th format specifier
 * @i: Pointer to the currnt index in the format strng
 * @list: Arguments
 * Return: Width value for formatting the output
 */

int get_width(const char *format, int *i, va_list list)
{
int curr_i;
int width = 0;

for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
width *= 10;
width += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
width = va_arg(list, int);
break;
}
else
{
break;
}
}

*i = curr_i - 1;

return (width);

>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
}
