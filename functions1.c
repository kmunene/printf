#include "main.h"

/*********************** PRINT UNSIGNED NUMBER ***********************/
/**
 * print_unsigned - Prints an unsigned integer number
 * @types: List a of alll  arguments in the program
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags in the program
 * @width: get width
 * @precision: Precision specification of the program
 * @size: Size specifier
 * Return: Number of characters  printed by _printf.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int zoo = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[zoo--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[zoo--] = (num % 10) + '0';
		num /= 10;
	}

	zoo++;

	return (write_unsgnd(0, zoo, buffer, flags, width, precision, size));
}

/*********** PRINT UNSIGNED NUMBER IN OCTAL  **************/
/**
 * print_octal - Prints all unsigned num in octal notation
 *
 * @types: Lists all arguments in the program
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags in the program
 * @width: get width of the characters
 * @precision: Precision specifier
 * @size: Size specifier of tghe program
 * Return: Number of chars printed by the code.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int zoo = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[zoo--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[zoo--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[zoo--] = '0';

	zoo++;

	return (write_unsgnd(0, zoo, buffer, flags, width, precision, size));
}

/************ PRINT UNSIGNED NUMBER IN HEXADECIMAL ************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal
 * @types: Lists all arguments in the program
 * @buffer: Buffer array
 * @flags:  Calculates active flags in the code
 * @width: get width pf the hexadecimal
 * @precision: Precision specification of decimals
 * @size: Size specifier
 * Return: Number of hexadecimals printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*********** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ***********/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments passed in the program
 * @buffer: Buffer array to handle print function
 * @flags:  Calculates active flags in the program
 * @width: get width
 * @precision: Precision specification of the program
 * @size: Size specifier
 * Return: Number of chars printed in upper hexadecimal
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int zoo = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[zoo--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[zoo--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[zoo--] = flag_ch;
		buffer[zoo--] = '0';
	}

	zoo++;

	return (write_unsgnd(0, zoo, buffer, flags, width, precision, size));
}
