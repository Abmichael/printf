#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define BUFFER_SIZE 1024
#define ABS(x) ((x) < 0 ? -(x) : (x))

typedef int (*converter_t)(va_list, char *, int);

typedef struct
{
	char specifier;
	converter_t converter;
} converter_entry_t;

int _printf(const char *format, ...);
int _strlen(char *s);
char *_itoa(long int num, int base, int uppercase);
void reverse_string(char *s, int i);
int convert_c(va_list args, char *buffer, int buffer_index);
int convert_s(va_list args, char *buffer, int buffer_index);
int convert_d(va_list args, char *buffer, int buffer_index);
int convert_i(va_list args, char *buffer, int buffer_index);
int convert_b(va_list args, char *buffer, int buffer_index);
int convert_u(va_list args, char *buffer, int buffer_index);
int convert_o(va_list args, char *buffer, int buffer_index);
int convert_x(va_list args, char *buffer, int buffer_index);
int convert_X(va_list args, char *buffer, int buffer_index);
int convert_S(va_list args, char *buffer, int buffer_index);
int convert_p(va_list args, char *buffer, int buffer_index);
int convert_r(va_list args, char *buffer, int buffer_index);
int convert_R(va_list args, char *buffer, int buffer_index);
int convert_unrecognized(va_list args, char *buffer, int buffer_index, char c);
int convert_percent(va_list args, char *buffer, int buffer_index);
converter_t get_converter(char c);

#endif
