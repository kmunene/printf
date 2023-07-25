#include "main.h"

/**
<<<<<<< HEAD
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_d = *i + 1;
	int siz = 0;

	if (format[curr_d] == 'l')
		siz = S_LONG;
	else if (format[curr_d] == 'h')
		siz = S_SHORT;

	if (siz == 0)
		*i = curr_d - 1;
	else
		*i = curr_d;

	return (siz);
=======
 * get_size - This function calculates the size to cast the argument
 * @format: Formatted strng containing the format specifier
 * @i: Pointer to the current index in the format string
 * Return: Size specifier for casting the argument
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == '1')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);

>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
}
