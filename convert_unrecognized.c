#include "main.h"

int convert_unrecognized(va_list args, char *buffer, int buffer_index, char c)
{
	(void)args;
	buffer[buffer_index++] = '%';
	buffer[buffer_index++] = c;
	return (buffer_index);
}
