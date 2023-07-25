#include "main.h"

/**
<<<<<<< HEAD
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
=======
 * get_flags - This function calculates active flags.
 * @format: Formatted string
 * into whicharguments are printed
 * @i: This function shows a pointer to the current index
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
    /* - + 0 # ' ' */
    /* 1 2 4 8 16 */
int j, curr_i;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
for (j = 0; FLAGS_CH[j] != '\0'; j++)
{
if (format[curr_i] == FLAGS_CH[j])
{
flags |= FLAGS_ARR[j];
break;
}
}

if (FLAGS_CH[j] == 0)
break;
}

*i = curr_i - 1;
return (flags);
}

>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd