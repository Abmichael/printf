#include "main.h"

/**
 * convert_d - Converts an int argument to decimal and stores
 * it in a buffer.
 * @args: A va_list pointing to the int to be converted.
 * @buffer: A pointer to the buffer to store the converted int.
 * @buffer_index: The index in the buffer where the converted
 * int should be stored.
 *
 * Return: The index in the buffer after storing the converted int.
 */
int convert_d(va_list args, char *buffer, int buffer_index)
{
	int num;
	char *str;
	int j;

	num = va_arg(args, int);
	str = _itoa(num, 10, 0);
	for (j = 0; str[j] != '\0'; j++)
		buffer[buffer_index++] = str[j];
	free(str);
	return (buffer_index);
}
