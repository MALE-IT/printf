#include "main.h"

/**
  *_printf - sends formatted output to stdout
  *@format: is a character string
  *string that contains the text to be written to stdout
  *Return: the number of characters printed
  *successful, the total number of characters
  *	On failure, a negative number is returned.
  */
int _printf(const char *format, ...)
{
	void print_buffer(char buffer[], int *buff_ind);

	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (format && format[i] != '\0')
		i++;
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
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
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
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (buffer == NULL || buff_ind == NULL || *buff_ind < 0)
	{
	return;
	}

	while (buffer[*buff_ind] != '\0')
	{
	_putchar(buffer[*buff_ind]);
	(*buff_ind)++;
	}
}
