#include "main.h"

int convert_s(va_list args, char *buffer, int buffer_index)
{
	char *str;
	int j;

	str = va_arg(args, char *);
	for (j = 0; str[j] != '\0'; j++)
		buffer[buffer_index++] = str[j];
	return (buffer_index);
}
