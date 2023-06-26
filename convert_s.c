#include "main.h"

/**
 * convert_s - Converts a string argument and stores it in a buffer.
 * @args: A va_list pointing to the string to be converted.
 * @buffer: A pointer to the buffer to store the converted string.
 * @buffer_index: The index in the buffer where the converted
 * string should be stored.
 *
 * Return: The index in the buffer after storing the converted string.
 */
int convert_s(va_list args, char *buffer, int buffer_index)
{
	char *str;
	int j;

	str = va_arg(args, char *);
	for (j = 0; str[j] != '\0'; j++)
		buffer[buffer_index++] = str[j];
	return (buffer_index);
}
