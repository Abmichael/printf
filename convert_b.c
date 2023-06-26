#include "main.h"

/**
 * convert_b - Converts an unsigned int argument to binary and stores
 * it in a buffer.
 * @args: A va_list pointing to the unsigned int to be converted.
 * @buffer: A pointer to the buffer to store the converted unsigned int.
 * @buffer_index: The index in the buffer where the converted unsigned
 * int should be stored.
 *
 * Return: The index in the buffer after storing the converted unsigned int.
 */
int convert_b(va_list args, char *buffer, int buffer_index)
{
	unsigned int num;
	char *str;
	int j;

	num = va_arg(args, unsigned int);
	str = _itoa(num, 2, 0);
	for (j = 0; str[j] != '\0'; j++)
		buffer[buffer_index++] = str[j];
	free(str);
	return (buffer_index);
}
