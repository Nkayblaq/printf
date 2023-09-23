#include "main.h"

/**
 * ... (your other function definitions) ...
 */

/**
 * printUnsigned - Print an unsigned integer as a string.
 * @num: The unsigned integer to be printed.
 * @buffer: The buffer to write the integer representation to.
 * @base: The base('o' for octal, 'x' for lowercase hex, 'X' for uppercase hex)
 *
 * Return: The number of characters written.
 */
int printUnsigned(unsigned int num, char *buffer, char base)
{
    char digits[] = "0123456789ABCDEF";
    char result[32];
    int i = 0;
    int count = 0;
    int j = 0;

    if (num == 0)
    {
        result[i++] = '0';
    }
    else
    {
        while (num > 0)
        {
            result[i++] = digits[num % base];
            num /= base;
        }
    }


    for (j = i - 1; j >= 0; j--)
    {
        buffer[count++] = result[j];
    }
    return count;
}

/**
 * printDecimal - Print a decimal integer as a string.
 * @num: The integer to be printed.
 * @buffer: The buffer to write the integer representation to.
 *
 * Return: The number of characters written.
 */
int printDecimal(signed int num, char *buffer)
{
    int count = 0;
    int temp = num;
    int numDigits = 0;
    int i;
    int divisor;
    int digit;

    if (num < 0)
    {
        buffer[count++] = '-';
        num = -num;
    }


    do
    {
        temp /= 10;
        numDigits++;
    } while (temp != 0);


    while (numDigits > 0)
    {
        divisor = 1;

        for (i = 1; i < numDigits; i++)
            divisor *= 10;
	digit = num / divisor;


        buffer[count++] = digit + '0';

        num %= divisor;
        numDigits--;
    }
    return count;
}

/**
 * _printf - A custom printf function that supports specifiers.
 * @format: The format string with optional specifiers.
 *
 * Return: The total number of characters written.
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
     char buffer[BUFFER_SIZE];
     int buffer_index = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format != '%')
        {
            buffer[buffer_index++] = *format;
            count++;

            if (buffer_index >= BUFFER_SIZE)
            {
                write(STDOUT_FILENO, buffer, buffer_index);
                buffer_index = 0;
            }
        }
        else
        {
            format++;

            if (*format == '\0')
                break;

            if (*format == 'd' || *format == 'i' || *format == 'u')
            {
                int num = va_arg(args, int);
                char tempBuffer[32];
                int written = printDecimal(num, tempBuffer);

                write(STDOUT_FILENO, tempBuffer, written);

                count += written;
            }
            else if (*format == '%')
            {
                buffer[buffer_index++] = '%';
                count++;

                if (buffer_index >= BUFFER_SIZE)
                {
                    write(STDOUT_FILENO, buffer, buffer_index);
                    buffer_index = 0;
                }
            }
            else if (*format == 'o' || *format == 'x' || *format == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                char tempBuffer[32];
                char base = (*format == 'o') ? 8 : 16;
                int written = printUnsigned(num, tempBuffer, base);

                write(STDOUT_FILENO, tempBuffer, written);

                count += written;
            }
        }
        format++;
    }

    if (buffer_index > 0)
    {
        write(STDOUT_FILENO, buffer, buffer_index);
    }

    va_end(args);
    return count;
}

