#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * write_char - Writes a character to standard output.
 * @c: The character to be written.
 *
 * Return: 1 if successful, -1 on error.
 */
int write_char(int c)
{
	return ((write(1, &c, 1) == -1 ? -1 : 1));
}

/**
 * write_string - Writes a string to standard output.
 * @s: The string to be written.
 *
 * Return: The number of characters written.
 */
int write_string(const char *s)
{
	int count = 0;

	while (*s)
	{
		count += write_char(*s);
		s++;
	}
	return (count);
}

/**
 * _printf - Outputs a formatted string to stdout.
 * @format: The format string.
 * @...: The variable number of arguments.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			count += write_char(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				count += write_char(va_arg(args, int));
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				if (s == NULL)
					s = "(null)";
				count += write_string(s);
			}
			else if (*format == '%')
			{
				count += write_char('%');
			}
		}
		format++;
	}
	
	va_end(args);
	return (count);
}
