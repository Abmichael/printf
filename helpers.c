#include "main.h"

/**
 * convert_percent - Stores a percent sign in a buffer.
 * @args: A va_list pointing to the argument to be converted.
 * @buffer: A pointer to the buffer to store the percent sign.
 * @buffer_index: The index in the buffer where the percent
 * sign should be stored.
 *
 * Return: The index in the buffer after storing the percent sign.
 */
int convert_percent(va_list args, char *buffer, int buffer_index)
{
	(void)args;

	buffer[buffer_index++] = '%';
	return (buffer_index);
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string to get the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * get_converter - Returns a pointer to a function that converts an argument
 * of a specified type and stores it in a buffer.
 * @c: The conversion specifier character.
 *
 * Return: A pointer to the appropriate conversion function, or NULL if no
 * conversion function exists for the specified type.
 */
converter_t get_converter(char c)
{
	switch (c)
	{
	case 'c':
		return (convert_c);
	case 's':
		return (convert_s);
	case '%':
		return (convert_percent);
	case 'd':
		return (convert_d);
	case 'i':
		return (convert_i);
	case 'b':
		return (convert_b);
	case 'u':
		return (convert_u);
	case 'o':
		return (convert_o);
	case 'x':
		return (convert_x);
	case 'X':
		return (convert_X);
	case 'p':
		return (convert_p);
	case 'S':
		return (convert_S);
	case 'r':
		return (convert_r);
	case 'R':
		return (convert_R);
	default:
		return (NULL);
	}
}

/**
 * reverse_string - Reverses a string in place.
 * @s: The string to reverse.
 * @i: The length of the string.
 */
void reverse_string(char *s, int i)
{
	int j;

	for (j = 0; j < i / 2; j++)
	{
		char tmp = s[j];

		s[j] = s[i - j - 1];
		s[i - j - 1] = tmp;
	}
}

/**
 * _itoa - Converts an integer to a string in a specified base and
 * stores it in a buffer.
 * @num: The integer to convert.
 * @base: The base to convert the integer to (2 <= base <= 36).
 * @uppercase: Whether or not to use uppercase letters for
 * bases > 10 (0 or 1).
 *
 * Return: A pointer to the buffer containing the converted integer.
 * This buffer must be freed by the caller.
 */
char *_itoa(long int num, int base, int uppercase)
{
	int i = 0, neg = 0;
	char *s = malloc(sizeof(char) * 33);

	if (num == 0)
	{
		s[i++] = '0';
		s[i] = '\0';
		return (s);
	}
	if (num < 0 && base == 10)
	{
		neg = 1;
		num = -num;
	}
	while (num != 0)
	{
		int rem = num % base;

		s[i++] = (rem > 9) ? (rem - 10) + (uppercase ? 'A' : 'a') : rem + '0';
		num /= base;
	}
	if (neg)
		s[i++] = '-';
	s[i] = '\0';
	reverse_string(s, i);
	return (s);
}
