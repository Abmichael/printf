#include "main.h"

/**
 * convert_S - Converts a string argument and stores it in a buffer.
 * @args: A va_list pointing to the string to be converted.
 * @buffer: A pointer to the buffer to store the converted string.
 * @buffer_index: The index in the buffer where the converted
 * string should be stored.
 *
 * Description: Non-printable characters (ASCII values < 32 or >= 127) are
 * converted to \x followed by their ASCII code value in hexadecimal.
 *
 * Return: The index in the buffer after storing the converted string.
 */
int convert_S(va_list args, char *buffer, int buffer_index)
{
	char *str;
	int j;
	int num;
	char *hex;
	int k;

	str = va_arg(args, char *);
	for (j = 0; str[j] != '\0'; j++)
	{
		if ((str[j] > 0 && str[j] < 32) || str[j] >= 127)
		{
			buffer[buffer_index++] = '\\';
			buffer[buffer_index++] = 'x';
			num = str[j];
			hex = _itoa(num, 16, 1);
			if (_strlen(hex) == 1)
				buffer[buffer_index++] = '0';
			for (k = 0; hex[k] != '\0'; k++)
				buffer[buffer_index++] = hex[k];
			free(hex);
		}
		else
			buffer[buffer_index++] = str[j];
	}
	return (buffer_index);
}
