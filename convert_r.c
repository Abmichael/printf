#include "main.h"

/**
 * convert_r - Converts an argument to a reversed string and
 *             copies it to the output buffer.
 * @args: A va_list of arguments from which to retrieve the string.
 * @buffer: A pointer to the output buffer.
 * @buffer_index: The current index of the output buffer.
 *
 * Return: The updated index of the output buffer.
 *
 * Description:
 * This function takes in a va_list of arguments, a pointer to the
 * output buffer and the current buffer index. It retrieves the string
 * argument using va_arg and reverses it character by character while
 * copying it to the output buffer. The function returns the updated
 * buffer index.
 */
int convert_r(va_list args, char *buffer, int buffer_index)
{
	char *str;
	int j, size;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";

	size = _strlen(str);
	for (j = 0; j < size; j++)
		buffer[buffer_index++] = str[size - j - 1];

	return (buffer_index);
}
