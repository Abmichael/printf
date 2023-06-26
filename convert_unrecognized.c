#include "main.h"

/**
 * convert_unrecognized - Stores an unrecognized conversion
 * specifier in a buffer.
 * @args: A va_list pointing to the argument to be converted.
 * @buffer: A pointer to the buffer to store the unrecognized
 * conversion specifier.
 * @buffer_index: The index in the buffer where the unrecognized
 * conversion specifier should be stored.
 * @c: The unrecognized conversion specifier character.
 *
 * Return: The index in the buffer after storing the
 * unrecognized conversion specifier.
 */
int convert_unrecognized(va_list args, char *buffer, int buffer_index, char c)
{
	(void)args;
	buffer[buffer_index++] = '%';
	buffer[buffer_index++] = c;
	return (buffer_index);
}
