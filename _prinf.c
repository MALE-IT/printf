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
	int printed_chars = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

		if (*format == '\0')
		{
			_putchar('%');
			printed_chars++;
		}
		else if (*format == 'c')
		{
			char ch = va_arg(args, int);
			_putchar(ch);
			printed_chars++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char *);
			printed_chars += printf("%s", str);
		}
		else if (*format == 'd')
		{
			int value = va_arg(args, int);
			printed_chars += printf("%d", value);
		}
		else if (*format == 'f')
		{
			double value = va_arg(args, double);
			printed_chars += printf("%f", value);
		}
		else if (*format == '%')
		{
			_putchar('%');
			printed_chars++;
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}
	} 
	else
	{
		_putchar(*format);
		printed_chars++;
	}
		format++;
	}

	va_end(args);

	return printed_chars;
}
