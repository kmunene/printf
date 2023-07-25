#include "main.h"

/**
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
}
