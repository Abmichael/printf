#include "main.h"

int convert_p(va_list args, char *buffer, int buffer_index)
{
	void *ptr;
	unsigned long int num;
	char *str;
	int j;

	ptr = va_arg(args, void *);
	num = (unsigned long int)ptr;
	buffer[buffer_index++] = '0';
	buffer[buffer_index++] = 'x';
	str = _itoa(num, 16, 0);
	for (j = 0; str[j] != '\0'; j++)
		buffer[buffer_index++] = str[j];
	free(str);
	return (buffer_index);
}
