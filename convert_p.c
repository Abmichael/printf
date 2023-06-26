#include "main.h"

/**
 * convert_p - Converts a pointer argument and stores it in a buffer.
 * @args: A va_list pointing to the pointer to be converted.
 * @buffer: A pointer to the buffer to store the converted pointer.
 * @buffer_index: The index in the buffer where the converted
 * pointer should be stored.
 *
 * Return: The index in the buffer after storing the converted pointer.
 */
int convert_p(va_list args, char *buffer, int buffer_index)
{
	void *ptr;
	unsigned long int num;
	char *str;
	int j;

	ptr = va_arg(args, void *);
	num = (unsigned long int)ptr;
	buffer[buffer_index++] = '0';
	buffer[buffer_index++] = 'x';
	str = _itoa(num, 16, 0);
	for (j = 0; str[j] != '\0'; j++)
		buffer[buffer_index++] = str[j];
	free(str);
	return (buffer_index);
}
