#include "main.h"

int convert_x(va_list args, char *buffer, int buffer_index)
{
	unsigned int num;
	char *str;
	int j;

	num = va_arg(args, unsigned int);
	str = _itoa(num, 16, 0);
	for (j = 0; str[j] != '\0'; j++)
		buffer[buffer_index++] = str[j];
	free(str);
	return (buffer_index);
}
