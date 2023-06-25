#include "main.h"

int convert_c(va_list args, char *buffer, int buffer_index)
{
	buffer[buffer_index++] = va_arg(args, int);
	return (buffer_index);
}
