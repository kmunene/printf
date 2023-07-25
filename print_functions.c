#include "main.h"

/************************* PRINT CHAR *************************/
<<<<<<< HEAD

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
=======
/**
 * print_char - This function prints a character.
 * @types: List of args.
 * @buffer: Buffer array
 * @flags: active flags calc.
 * @width: Width.
 * @precision: Precision specifier
 * @size: Size specification
 * Return: No. of chars to be printed
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (handle_write_char(c, buffer, flags, width, precision, size));

}

/************************* PRINT A STRING *************************/
/**
 * print_string - This function prrints a string.
 * @types: Arguments
 * @buffer: Buffer array
 * @flags: Calculation of active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: No. of chars
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
{
	int length = 0, i;
	char *str = va_arg(types, char *);

<<<<<<< HEAD
	UNUSED(buffer);
=======
>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
<<<<<<< HEAD
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
=======

	if (str == NULL)
		str = "(null)";
>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
<<<<<<< HEAD

	return (write(1, str, length));
}


/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
=======
	return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - This function prints % sign
 * @types: arguments.
 * @buffer: Buffer array
 * @flags: active flags calc.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: No. of chars printed
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
<<<<<<< HEAD
=======

>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
<<<<<<< HEAD
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * 
@size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
=======
 * print_int - This function prints int.
 * @types:  arguments.
 * @buffer: Buffer array
 * @flags: Calc. of active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

<<<<<<< HEAD
=======

>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;
<<<<<<< HEAD

=======
>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
<<<<<<< HEAD
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

=======
 * in binary format.
 * @types: arguments.
 * @buffer: Buffer array
 * @flags: Calculation of active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Numbers of characters
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
<<<<<<< HEAD
=======

>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
<<<<<<< HEAD
=======

>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
<<<<<<< HEAD
			count++;
		}
	}
	return (count);
}
=======


			count++;

		}

	}

	return (count);

}

>>>>>>> 9b606aab157324e1ebaf3519f0e875f6392257fd
