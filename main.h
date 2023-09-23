#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int write_string(const char *s);
int write_char(int c);
int printDecimal(signed int num, char *buffer);
int printUnsigned(unsigned int num, char *buffer, char base);

#endif
