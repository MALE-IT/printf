#include "main.h"

/***********************handling conversion specifiers:c***************/

/**
  *_printf - printf-like function named
  *@format: defines the output format
  *print _char - prints char
  *Return: char
  */
int _printf(const char *format, ...)
{
	int printed_chars = 0;

	(*format == 'c');

	char c = va_arg(args, int);

	_putchar(c);
	printed_chars++;
}

/************************handling of conversion specifiers:s***************/

/**
  *_printf - printf-like function named
  *@format: defines the output format
  *print_string - print the string
  *
  *Return: the string
  */
int _printf(const char *format, ...)
{
	int printed_chars = 0;

	*format == 's';

	char *str = va_arg(args, char *);

	printed_chars += _printf("%s", str);
}

/********************handling of conversion specefiers: % ********************/

/**
  *_printf - printf-like function named
  *@format: defines the output format
  *print_percent - printa a percent sign
  *
  *Return: the percent sign
  */
int _printf(const char *format, ...)
{
	int printed_chars = 0;

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
	}
	}
}
