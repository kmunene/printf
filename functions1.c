#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints unsigned 
 * @types: List of arguments
 * @buffer: fer array to handle print
 * @flags:  Cal active flags
 * @width: get w
 * @precision: Precision specification
 * @size: Size specifier
 * Display unsigned uter..
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigneal notation
 * @types: List of arguments
 * @buffer: Buffer array  print
 * @flags:  Calcultive flags
 * @width: get wth
 * @precision: Pre ecification
 * @size: Size specifier
 * Display Octal number..
 *
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an l notation
 * @types: List of argum
 * @buffer: Buffer  to handle print
 * @flags:  Calculates lags
 * @width: get width
 * @precision: Precision spec
 * @size: Size specifier
 * Display unsigned hal numbner
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - A function per hexadecimal notation
 * @types: Lista of 
 * @buffer: rray to handle print
 * @flags:  Calcve flags
 * @width: get width
 * @precision: Precision spion
 * @size: Size specifier
 * Display unsiin upper hexadecimal..
 *
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hex upper
 * @types: List of ar
 * @map_to: Ar values to map the number to
 * @buffer: B ray to handle print
 * @flags:  Cal s active flags
 * @flag_ch:  ulates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Display hexx number either lower or upper
 *
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
