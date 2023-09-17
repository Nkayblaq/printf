#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: character string
 * Return: the number of characters printed (excluding the null byte)
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
                int c = va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*format == 's')
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
    return count;
}

