#include "main.h"

/***** PRINTING OF UNSIGNED NUMBER *****/
/**
 * print_unsigned - This  prints unsigned number
 * @buffer: Buffer for prints
 * @types: Listing of  arguments
 * @precision: Precisions
 * @size: Size specifier
 * @flags:  Calculation of flags
 * @width: for width
 * Return: Characters to be printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[a--] = (numb % 10) + '0';
		numb /= 10;
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN OCTAL**/
/**
 * print_octal - This  prints unsigned number
 * @buffer: Buffer for prints
 * @types: Listing of  arguments
 * @precision: Precisions
 * @size: Size specifier
 * @flags:  Calculation of flags
 * @width: for width
 * Return: Characters to be printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_num = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[a--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & F_HASH && init_numb != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**PRINTING NUMBER**/
/**
 * print_hexadecimal - This prints a number in hexadecimal
 * @buffer: Buffer for prints
 * @types: Listing of  arguments
 * @precision: Precisions
 * @size: Size specifier
 * @flags:  Calculation of flags
 * @width: for width
 * Return: Characters to be printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**PRINTING NUMBER**/
/**
 * print_hexa_upper - Printing number in upper
 * @buffer: Buffer for prints
 * @types: Listing of  arguments
 * @precision: Precisions
 * @size: Size specifier
 * @flags:  Calculation of flags
 * @width: for width
 * Return: Characters to be printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/** PRINTING IN UPPER OR LOWER**/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates flags
 * @width: get width
 * @precision: Precise size
 * @size: Size
 * @size: Size specific
 * Return: Characters to be printed
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
