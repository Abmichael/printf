#include "main.h"

/**
 * convert_c - Converts a char argument and stores it in a buffer.
 * @args: A va_list pointing to the char to be converted.
 * @buffer: A pointer to the buffer to store the converted char.
 * @buffer_index: The index in the buffer where the converted
 * char should be stored.
 *
 * Return: The index in the buffer after storing the converted char.
 */
int convert_c(va_list args, char *buffer, int buffer_index)
{
	buffer[buffer_index++] = va_arg(args, int);
	return (buffer_index);
}
