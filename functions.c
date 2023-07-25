#include "main.h"

/*handling conversion specifiers:c */
i
/**
  *print _char - prints char
  *@types: handle an arbitrary number of arguments.
  *@buffer: array of characters(a string) that will store the formatted output.
  *@flags: used to specify various formatting options.
  *@width: An integer representing the minimum width of the output
  *@precision: specifies the precision for certain data types
  *@size: used to indicate the size of the buffer array to
  *prevent buffer overflows
  *
  *Return: char
  */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/*********handling of conversion specifiers:s*/

/**
  *print _string - print the string (s)
  *@types: handle an arbitrary number of arguments.
  *@buffer: array of characters(a string) that will store the formatted output.
  *@flags: used to specify various formatting options.
  *@width: An integer representing the minimum width of the output
  *@precision: specifies the precision for certain data types
  *@size: used to indicate the size of the buffer array to
  *prevent buffer overflows
  *
  *Return: String of characters
  */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)

	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}
	for (length = 0; str[length] != '\0'; length++)
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
	return (write(1, str, length));
}

/******handling of conversion specefiers: % */

/**
  *print _modulo_operator - prints % Character
  *@types: handle an arbitrary number of arguments.
  *@buffer: array of characters(a string) that will store the formatted output.
  *@flags: used to specify various formatting options.
  *@width: An integer representing the minimum width of the output
  *@precision: specifies the precision for certain data types
  *@size: used to indicate the size of the buffer array to
  *prevent buffer overflows
  *
  *Return: % character
  */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
