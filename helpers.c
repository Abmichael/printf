#include "main.h"

int convert_percent(va_list args, char *buffer, int buffer_index)
{
	(void)args;

	buffer[buffer_index++] = '%';
	return (buffer_index);
}

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
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
	default:
		return (NULL);
	}
}

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
