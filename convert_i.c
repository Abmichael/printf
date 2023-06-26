#include "main.h"

/**
 * convert_i - Converts an int argument to decimal and stores
 * it in a buffer.
 * @args: A va_list pointing to the int to be converted.
 * @buffer: A pointer to the buffer to store the converted int.
 * @buffer_index: The index in the buffer where the converted
 * int should be stored.
 *
 * Return: The index in the buffer after storing the converted int.
 *
 * Note: This function is equivalent to calling convert_d with
 * the same arguments.
 */
int convert_i(va_list args, char *buffer, int buffer_index)
{
	return (convert_d(args, buffer, buffer_index));
}
