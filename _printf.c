#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Helper function to print a character
 * @args: A va_list containing the arguments.
 * @count: The current character count.
 * Return: The updated character count.
 */
static int print_char(va_list args, int count)
{
	int c = va_arg(args, int);

	putchar(c);
	return (count + 1);
}

/**
 * print_string - Helper function to print a string
 * @args: A va_list containing the arguments.
 * @count: The current character count.
 * Return: The updated character count.
 */
static int print_string(va_list args, int count)
{
	char *s = va_arg(args, char *);

	if (s != NULL)
	{
		while (*s != '\0')
		{
			putchar(*s);
			s++;
			count++;
		}
	}
	else
	{
		printf("(null)");
		count += 6;
	}
	return (count);
}

/**
 * _printf - Main function to format and print output
 * @format: A character string containing format specifiers.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				count = print_char(args, count);
			}
			else if (*format == 's')
			{
				count = print_string(args, count);
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
