#include "main.h"

int convert_i(va_list args, char *buffer, int buffer_index)
{
	return (convert_d(args, buffer, buffer_index));
}
