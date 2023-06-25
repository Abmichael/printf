#include <stdarg.h>
#include <unistd.h>

#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	int i;
	converter_t converter;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			converter = get_converter(format[i]);
			if (converter != NULL)
				buffer_index = converter(args, buffer, buffer_index);
			else
				buffer_index = convert_unrecognized(args, buffer, buffer_index, format[i]);
		}
		else
			buffer[buffer_index++] = format[i];
		if (buffer_index == BUFFER_SIZE)
		{
			write(1, buffer, BUFFER_SIZE);
			count += BUFFER_SIZE;
			buffer_index = 0;
		}
	}
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
		count += buffer_index;
	}
	va_end(args);
	return (count);
}
