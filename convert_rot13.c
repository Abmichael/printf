#include "main.h"

/**
 * convert_R - Converts a string argument to rot13 and stores it in a buffer.
 * @args: A va_list pointing to the string to be converted.
 * @buffer: A pointer to the buffer to store the converted string.
 * @buffer_index: The index in the buffer where the converted string
 * should be stored.
 *
 * Return: The index in the buffer after storing the converted string.
 */
int convert_R(va_list args, char *buffer, int buffer_index)
{
	char *str;
	int j;

	str = va_arg(args, char *);
	for (j = 0; str[j] != '\0'; j++)
	{
		if ((str[j] >= 'a' && str[j] <= 'm') || (str[j] >= 'A' && str[j] <= 'M'))
			buffer[buffer_index++] = str[j] + 13;
		else if ((str[j] >= 'n' && str[j] <= 'z') ||
				 (str[j] >= 'N' && str[j] <= 'Z'))
			buffer[buffer_index++] = str[j] - 13;
		else
			buffer[buffer_index++] = str[j];
	}
	return (buffer_index);
}
